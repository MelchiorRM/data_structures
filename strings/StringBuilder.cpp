#include "StringBuilder.hpp"
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <cstdarg>

// Constructor and Destructor
StringBuilder::StringBuilder() : length(0), capacity(INITIAL_CAPACITY), bufferSize(0) {
    data = new char[capacity];
    data[0] = '\0';
}

StringBuilder::StringBuilder(const char* str) : length(0), capacity(INITIAL_CAPACITY), bufferSize(0) {
    data = new char[capacity];
    createString(str);
}

StringBuilder::StringBuilder(const std::string& str) : length(0), capacity(INITIAL_CAPACITY), bufferSize(0) {
    data = new char[capacity];
    createString(str);
}

StringBuilder::StringBuilder(int size) : length(0), capacity(INITIAL_CAPACITY), bufferSize(0) {
    data = new char[capacity];
    createString(size);
}

StringBuilder::StringBuilder(const StringBuilder& other) : length(other.length), capacity(other.capacity), bufferSize(other.bufferSize) {
    data = new char[capacity];
    strcpy(data, other.data);
}

StringBuilder::~StringBuilder() {
    delete[] data;
}

// Assignment operator
StringBuilder& StringBuilder::operator=(const StringBuilder& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        capacity = other.capacity;
        bufferSize = other.bufferSize;
        data = new char[capacity];
        strcpy(data, other.data);
    }
    return *this;
}

StringBuilder& StringBuilder::operator=(const char* str) {
    createString(str);
    return *this;
}

StringBuilder& StringBuilder::operator=(const std::string& str) {
    createString(str);
    return *this;
}

// Basic String Operations
void StringBuilder::createString(const char* str) {
    if (!str) {
        length = 0;
        data[0] = '\0';
        return;
    }
    
    int strLen = strlen(str);
    ensureCapacity(strLen + 1);
    strcpy(data, str);
    length = strLen;
    bufferSize = 0;
}

void StringBuilder::createString(const std::string& str) {
    createString(str.c_str());
}

void StringBuilder::createString(int size) {
    if (size < 0) {
        size = 0;
    }
    
    ensureCapacity(size + 1);
    memset(data, '\0', size + 1);
    length = size;
    bufferSize = 0;
}

void StringBuilder::display() const {
    std::cout << data;
}

void StringBuilder::clear() {
    length = 0;
    data[0] = '\0';
    bufferSize = 0;
}

bool StringBuilder::isEmpty() const {
    return length == 0;
}

int StringBuilder::getLength() const {
    return length;
}

int StringBuilder::getCapacity() const {
    return capacity;
}

// Character Operations
char StringBuilder::getCharAt(int position) const {
    if (!isValidPosition(position)) {
        return '\0';
    }
    return data[position];
}

void StringBuilder::setCharAt(int position, char ch) {
    if (!isValidPosition(position)) {
        return;
    }
    data[position] = ch;
}

void StringBuilder::insertCharAt(int position, char ch) {
    if (position < 0 || position > length) {
        return;
    }
    
    ensureCapacity(length + 2);
    shiftRight(position, 1);
    data[position] = ch;
    length++;
    data[length] = '\0';
}

void StringBuilder::deleteCharAt(int position) {
    if (!isValidPosition(position)) {
        return;
    }
    
    shiftLeft(position, 1);
    length--;
    data[length] = '\0';
}

void StringBuilder::appendChar(char ch) {
    ensureCapacity(length + 2);
    data[length] = ch;
    length++;
    data[length] = '\0';
}

void StringBuilder::prependChar(char ch) {
    insertCharAt(0, ch);
}

// String Manipulation
void StringBuilder::append(const char* str) {
    if (!str) {
        return;
    }
    
    int strLen = strlen(str);
    ensureCapacity(length + strLen + 1);
    strcat(data, str);
    length += strLen;
}

void StringBuilder::append(const std::string& str) {
    append(str.c_str());
}

void StringBuilder::prepend(const char* str) {
    if (!str) {
        return;
    }
    
    int strLen = strlen(str);
    ensureCapacity(length + strLen + 1);
    shiftRight(0, strLen);
    strncpy(data, str, strLen);
    length += strLen;
    data[length] = '\0';
}

void StringBuilder::prepend(const std::string& str) {
    prepend(str.c_str());
}

void StringBuilder::insertAt(int position, const char* str) {
    if (!str || position < 0 || position > length) {
        return;
    }
    
    int strLen = strlen(str);
    ensureCapacity(length + strLen + 1);
    shiftRight(position, strLen);
    strncpy(data + position, str, strLen);
    length += strLen;
    data[length] = '\0';
}

void StringBuilder::insertAt(int position, const std::string& str) {
    insertAt(position, str.c_str());
}

void StringBuilder::deleteAt(int position, int count) {
    if (position < 0 || position >= length || count <= 0) {
        return;
    }
    
    int actualCount = std::min(count, length - position);
    shiftLeft(position + actualCount, actualCount);
    length -= actualCount;
    data[length] = '\0';
}

void StringBuilder::replace(const char* oldStr, const char* newStr) {
    if (!oldStr || !newStr) {
        return;
    }
    
    int oldLen = strlen(oldStr);
    int newLen = strlen(newStr);
    int pos = find(oldStr);
    
    while (pos != -1) {
        deleteAt(pos, oldLen);
        insertAt(pos, newStr);
        pos = find(oldStr);
    }
}

void StringBuilder::replace(const std::string& oldStr, const std::string& newStr) {
    replace(oldStr.c_str(), newStr.c_str());
}

// String Search and Comparison
int StringBuilder::find(const char* substr) const {
    if (!substr || length == 0) {
        return -1;
    }
    
    char* result = strstr(data, substr);
    return result ? result - data : -1;
}

int StringBuilder::find(const std::string& substr) const {
    return find(substr.c_str());
}

int StringBuilder::findLast(const char* substr) const {
    if (!substr || length == 0) {
        return -1;
    }
    
    int pos = -1;
    int currentPos = 0;
    char* result = strstr(data, substr);
    
    while (result) {
        pos = result - data;
        currentPos = pos + 1;
        result = strstr(data + currentPos, substr);
    }
    
    return pos;
}

int StringBuilder::findLast(const std::string& substr) const {
    return findLast(substr.c_str());
}

int StringBuilder::findChar(char ch) const {
    char* result = strchr(data, ch);
    return result ? result - data : -1;
}

int StringBuilder::findLastChar(char ch) const {
    char* result = strrchr(data, ch);
    return result ? result - data : -1;
}

bool StringBuilder::startsWith(const char* prefix) const {
    if (!prefix) {
        return false;
    }
    
    int prefixLen = strlen(prefix);
    if (prefixLen > length) {
        return false;
    }
    
    return strncmp(data, prefix, prefixLen) == 0;
}

bool StringBuilder::startsWith(const std::string& prefix) const {
    return startsWith(prefix.c_str());
}

bool StringBuilder::endsWith(const char* suffix) const {
    if (!suffix) {
        return false;
    }
    
    int suffixLen = strlen(suffix);
    if (suffixLen > length) {
        return false;
    }
    
    return strncmp(data + length - suffixLen, suffix, suffixLen) == 0;
}

bool StringBuilder::endsWith(const std::string& suffix) const {
    return endsWith(suffix.c_str());
}

bool StringBuilder::contains(const char* substr) const {
    return find(substr) != -1;
}

bool StringBuilder::contains(const std::string& substr) const {
    return contains(substr.c_str());
}

int StringBuilder::compare(const char* str) const {
    if (!str) {
        return length > 0 ? 1 : 0;
    }
    return strcmp(data, str);
}

int StringBuilder::compare(const std::string& str) const {
    return compare(str.c_str());
}

int StringBuilder::compare(const String& str) const {
    return compare(str.toCString());
}

bool StringBuilder::equals(const char* str) const {
    return compare(str) == 0;
}

bool StringBuilder::equals(const std::string& str) const {
    return equals(str.c_str());
}

bool StringBuilder::equals(const String& str) const {
    return equals(str.toCString());
}

// String Transformation
void StringBuilder::toUpperCase() {
    for (int i = 0; i < length; i++) {
        data[i] = toupper(data[i]);
    }
}

void StringBuilder::toLowerCase() {
    for (int i = 0; i < length; i++) {
        data[i] = tolower(data[i]);
    }
}

void StringBuilder::reverse() {
    for (int i = 0; i < length / 2; i++) {
        std::swap(data[i], data[length - 1 - i]);
    }
}

void StringBuilder::trim() {
    trimLeft();
    trimRight();
}

void StringBuilder::trimLeft() {
    int start = 0;
    while (start < length && isspace(data[start])) {
        start++;
    }
    
    if (start > 0) {
        shiftLeft(start, start);
        length -= start;
        data[length] = '\0';
    }
}

void StringBuilder::trimRight() {
    int end = length - 1;
    while (end >= 0 && isspace(data[end])) {
        end--;
    }
    
    length = end + 1;
    data[length] = '\0';
}

void StringBuilder::removeWhitespace() {
    int writePos = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(data[i])) {
            data[writePos++] = data[i];
        }
    }
    length = writePos;
    data[length] = '\0';
}

void StringBuilder::removeDuplicates() {
    // Simple implementation - remove consecutive duplicates
    if (length <= 1) {
        return;
    }
    
    int writePos = 1;
    for (int i = 1; i < length; i++) {
        if (data[i] != data[writePos - 1]) {
            data[writePos++] = data[i];
        }
    }
    length = writePos;
    data[length] = '\0';
}

// Substring Operations
String* StringBuilder::substring(int start, int end) const {
    if (!isValidRange(start, end)) {
        return new StringBuilder();
    }
    
    int subLen = end - start;
    StringBuilder* result = new StringBuilder();
    result->ensureCapacity(subLen + 1);
    strncpy(result->data, data + start, subLen);
    result->data[subLen] = '\0';
    result->length = subLen;
    
    return result;
}

String* StringBuilder::substring(int start) const {
    return substring(start, length);
}

void StringBuilder::extractSubstring(int start, int end, char* buffer) const {
    if (!buffer || !isValidRange(start, end)) {
        return;
    }
    
    int subLen = end - start;
    strncpy(buffer, data + start, subLen);
    buffer[subLen] = '\0';
}

void StringBuilder::extractSubstring(int start, char* buffer) const {
    extractSubstring(start, length, buffer);
}

// String Analysis
int StringBuilder::countOccurrences(const char* substr) const {
    if (!substr || length == 0) {
        return 0;
    }
    
    int count = 0;
    int pos = 0;
    int substrLen = strlen(substr);
    
    while ((pos = find(substr)) != -1) {
        count++;
        pos += substrLen;
        if (pos >= length) break;
    }
    
    return count;
}

int StringBuilder::countOccurrences(const std::string& substr) const {
    return countOccurrences(substr.c_str());
}

int StringBuilder::countOccurrences(char ch) const {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == ch) {
            count++;
        }
    }
    return count;
}

int StringBuilder::countWords() const {
    if (length == 0) {
        return 0;
    }
    
    int wordCount = 0;
    bool inWord = false;
    
    for (int i = 0; i < length; i++) {
        if (isspace(data[i])) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            wordCount++;
        }
    }
    
    return wordCount;
}

int StringBuilder::countLines() const {
    return countOccurrences('\n') + 1;
}

bool StringBuilder::isNumeric() const {
    if (length == 0) {
        return false;
    }
    
    for (int i = 0; i < length; i++) {
        if (!isdigit(data[i]) && data[i] != '.' && data[i] != '-' && data[i] != '+') {
            return false;
        }
    }
    return true;
}

bool StringBuilder::isAlpha() const {
    if (length == 0) {
        return false;
    }
    
    for (int i = 0; i < length; i++) {
        if (!isalpha(data[i])) {
            return false;
        }
    }
    return true;
}

bool StringBuilder::isAlphaNumeric() const {
    if (length == 0) {
        return false;
    }
    
    for (int i = 0; i < length; i++) {
        if (!isalnum(data[i])) {
            return false;
        }
    }
    return true;
}

// String Conversion
std::string StringBuilder::toString() const {
    return std::string(data);
}

const char* StringBuilder::toCString() const {
    return data;
}

int StringBuilder::toInt() const {
    return std::stoi(data);
}

double StringBuilder::toDouble() const {
    return std::stod(data);
}

// Advanced Operations
void StringBuilder::resize(int newSize) {
    if (newSize < 0) {
        return;
    }
    
    ensureCapacity(newSize + 1);
    length = newSize;
    data[length] = '\0';
}

void StringBuilder::reserve(int newCapacity) {
    if (newCapacity > capacity) {
        ensureCapacity(newCapacity);
    }
}

void StringBuilder::shrinkToFit() {
    if (length + 1 < capacity) {
        reallocate(length + 1);
    }
}

String* StringBuilder::clone() const {
    return new StringBuilder(*this);
}

void StringBuilder::swap(String& other) {
    StringBuilder* otherBuilder = dynamic_cast<StringBuilder*>(&other);
    if (otherBuilder) {
        std::swap(data, otherBuilder->data);
        std::swap(length, otherBuilder->length);
        std::swap(capacity, otherBuilder->capacity);
        std::swap(bufferSize, otherBuilder->bufferSize);
    }
}

void StringBuilder::concatenate(const String& other) {
    append(other.toCString());
}

void StringBuilder::concatenate(const char* str) {
    append(str);
}

void StringBuilder::concatenate(const std::string& str) {
    append(str);
}

// String Splitting and Joining
String** StringBuilder::split(const char* delimiter) const {
    // TODO: Implement string splitting
    return nullptr;
}

String** StringBuilder::split(const std::string& delimiter) const {
    return split(delimiter.c_str());
}

String** StringBuilder::split(char delimiter) const {
    // TODO: Implement character splitting
    return nullptr;
}

String* StringBuilder::join(const String* strings[], int count, const char* separator) const {
    // TODO: Implement string joining
    return nullptr;
}

String* StringBuilder::join(const String* strings[], int count, const std::string& separator) const {
    return join(strings, count, separator.c_str());
}

// Pattern Matching
bool StringBuilder::matches(const char* pattern) const {
    // TODO: Implement pattern matching
    return false;
}

bool StringBuilder::matches(const std::string& pattern) const {
    return matches(pattern.c_str());
}

int StringBuilder::findPattern(const char* pattern) const {
    // TODO: Implement pattern finding
    return -1;
}

int StringBuilder::findPattern(const std::string& pattern) const {
    return findPattern(pattern.c_str());
}

void StringBuilder::replacePattern(const char* pattern, const char* replacement) {
    // TODO: Implement pattern replacement
}

void StringBuilder::replacePattern(const std::string& pattern, const std::string& replacement) {
    replacePattern(pattern.c_str(), replacement.c_str());
}

// Memory Management
void StringBuilder::free() {
    delete[] data;
    data = nullptr;
    length = 0;
    capacity = 0;
    bufferSize = 0;
}

// StringBuilder specific operations
void StringBuilder::appendLine(const char* str) {
    append(str);
    appendChar('\n');
}

void StringBuilder::appendLine(const std::string& str) {
    appendLine(str.c_str());
}

void StringBuilder::appendLine() {
    appendChar('\n');
}

void StringBuilder::appendFormat(const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    // Calculate required size
    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(nullptr, 0, format, args_copy);
    va_end(args_copy);
    
    if (size > 0) {
        ensureCapacity(length + size + 1);
        vsnprintf(data + length, size + 1, format, args);
        length += size;
    }
    
    va_end(args);
}

void StringBuilder::appendNumber(int number) {
    appendFormat("%d", number);
}

void StringBuilder::appendNumber(double number) {
    appendFormat("%.6f", number);
}

void StringBuilder::appendNumber(long number) {
    appendFormat("%ld", number);
}

void StringBuilder::insertLineAt(int position, const char* str) {
    insertAt(position, str);
    insertCharAt(position + strlen(str), '\n');
}

void StringBuilder::insertLineAt(int position, const std::string& str) {
    insertLineAt(position, str.c_str());
}

void StringBuilder::insertLineAt(int position) {
    insertCharAt(position, '\n');
}

void StringBuilder::replaceLine(int lineNumber, const char* str) {
    int lineStart = findLineStart(lineNumber);
    int lineEnd = findLineEnd(lineNumber);
    
    if (lineStart != -1 && lineEnd != -1) {
        deleteAt(lineStart, lineEnd - lineStart);
        insertAt(lineStart, str);
    }
}

void StringBuilder::replaceLine(int lineNumber, const std::string& str) {
    replaceLine(lineNumber, str.c_str());
}

void StringBuilder::deleteLine(int lineNumber) {
    int lineStart = findLineStart(lineNumber);
    int lineEnd = findLineEnd(lineNumber);
    
    if (lineStart != -1 && lineEnd != -1) {
        deleteAt(lineStart, lineEnd - lineStart + 1);
    }
}

void StringBuilder::insertAtLine(int lineNumber, const char* str) {
    int lineStart = findLineStart(lineNumber);
    if (lineStart != -1) {
        insertAt(lineStart, str);
    }
}

void StringBuilder::insertAtLine(int lineNumber, const std::string& str) {
    insertAtLine(lineNumber, str.c_str());
}

// Buffer management
void StringBuilder::ensureBufferCapacity(int requiredCapacity) {
    ensureCapacity(requiredCapacity);
}

void StringBuilder::optimizeBuffer() {
    if (length < capacity / 2) {
        reallocate(length + 1);
    }
}

void StringBuilder::flushBuffer() {
    // For StringBuilder, this is a no-op as we don't use buffering
    // This method is kept for interface compatibility
}

int StringBuilder::getBufferSize() const {
    return bufferSize;
}

// Operator overloads
StringBuilder StringBuilder::operator+(const StringBuilder& other) const {
    StringBuilder result = *this;
    result.append(other.data);
    return result;
}

StringBuilder StringBuilder::operator+(const char* str) const {
    StringBuilder result = *this;
    result.append(str);
    return result;
}

StringBuilder StringBuilder::operator+(const std::string& str) const {
    StringBuilder result = *this;
    result.append(str);
    return result;
}

StringBuilder& StringBuilder::operator+=(const StringBuilder& other) {
    append(other.data);
    return *this;
}

StringBuilder& StringBuilder::operator+=(const char* str) {
    append(str);
    return *this;
}

StringBuilder& StringBuilder::operator+=(const std::string& str) {
    append(str);
    return *this;
}

char& StringBuilder::operator[](int index) {
    return data[index];
}

const char& StringBuilder::operator[](int index) const {
    return data[index];
}

// Helper methods
void StringBuilder::ensureCapacity(int requiredCapacity) {
    if (requiredCapacity > capacity) {
        int newCapacity = capacity;
        while (newCapacity < requiredCapacity) {
            newCapacity *= GROWTH_FACTOR;
        }
        reallocate(newCapacity);
    }
}

void StringBuilder::growCapacity() {
    reallocate(capacity * GROWTH_FACTOR);
}

void StringBuilder::shrinkCapacity() {
    if (length < capacity / GROWTH_FACTOR) {
        reallocate(capacity / GROWTH_FACTOR);
    }
}

bool StringBuilder::isValidPosition(int position) const {
    return position >= 0 && position < length;
}

bool StringBuilder::isValidRange(int start, int end) const {
    return start >= 0 && start < length && end > start && end <= length;
}

void StringBuilder::shiftRight(int position, int count) {
    for (int i = length - 1; i >= position; i--) {
        data[i + count] = data[i];
    }
}

void StringBuilder::shiftLeft(int position, int count) {
    for (int i = position; i < length; i++) {
        data[i - count] = data[i];
    }
}

int StringBuilder::calculateNewLength(const char* str) const {
    return strlen(str);
}

void StringBuilder::copyString(const char* source, char* destination, int count) {
    strncpy(destination, source, count);
}

void StringBuilder::reallocate(int newCapacity) {
    char* newData = new char[newCapacity];
    strcpy(newData, data);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

int StringBuilder::findLineStart(int lineNumber) const {
    if (lineNumber < 0) {
        return -1;
    }
    
    int currentLine = 0;
    for (int i = 0; i < length; i++) {
        if (currentLine == lineNumber) {
            return i;
        }
        if (data[i] == '\n') {
            currentLine++;
        }
    }
    
    return currentLine == lineNumber ? length : -1;
}

int StringBuilder::findLineEnd(int lineNumber) const {
    int lineStart = findLineStart(lineNumber);
    if (lineStart == -1) {
        return -1;
    }
    
    for (int i = lineStart; i < length; i++) {
        if (data[i] == '\n') {
            return i;
        }
    }
    
    return length;
}

int StringBuilder::countLinesInRange(int start, int end) const {
    int count = 0;
    for (int i = start; i < end && i < length; i++) {
        if (data[i] == '\n') {
            count++;
        }
    }
    return count;
}

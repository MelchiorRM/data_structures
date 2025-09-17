#include "DynamicString.hpp"
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>

// Constructor and Destructor
DynamicString::DynamicString() : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    data[0] = '\0';
}

DynamicString::DynamicString(const char* str) : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    createString(str);
}

DynamicString::DynamicString(const std::string& str) : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    createString(str);
}

DynamicString::DynamicString(int size) : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    createString(size);
}

DynamicString::DynamicString(const DynamicString& other) : length(other.length), capacity(other.capacity) {
    data = new char[capacity];
    strcpy(data, other.data);
}

DynamicString::~DynamicString() {
    delete[] data;
}

// Assignment operator
DynamicString& DynamicString::operator=(const DynamicString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        capacity = other.capacity;
        data = new char[capacity];
        strcpy(data, other.data);
    }
    return *this;
}

DynamicString& DynamicString::operator=(const char* str) {
    createString(str);
    return *this;
}

DynamicString& DynamicString::operator=(const std::string& str) {
    createString(str);
    return *this;
}

// Basic String Operations
void DynamicString::createString(const char* str) {
    if (!str) {
        length = 0;
        data[0] = '\0';
        return;
    }
    
    int strLen = strlen(str);
    ensureCapacity(strLen + 1);
    strcpy(data, str);
    length = strLen;
}

void DynamicString::createString(const std::string& str) {
    createString(str.c_str());
}

void DynamicString::createString(int size) {
    if (size < 0) {
        size = 0;
    }
    
    ensureCapacity(size + 1);
    memset(data, '\0', size + 1);
    length = size;
}

void DynamicString::display() const {
    std::cout << data;
}

void DynamicString::clear() {
    length = 0;
    data[0] = '\0';
}

bool DynamicString::isEmpty() const {
    return length == 0;
}

int DynamicString::getLength() const {
    return length;
}

int DynamicString::getCapacity() const {
    return capacity;
}

// Character Operations
char DynamicString::getCharAt(int position) const {
    if (!isValidPosition(position)) {
        return '\0';
    }
    return data[position];
}

void DynamicString::setCharAt(int position, char ch) {
    if (!isValidPosition(position)) {
        return;
    }
    data[position] = ch;
}

void DynamicString::insertCharAt(int position, char ch) {
    if (position < 0 || position > length) {
        return;
    }
    
    ensureCapacity(length + 2);
    shiftRight(position, 1);
    data[position] = ch;
    length++;
    data[length] = '\0';
}

void DynamicString::deleteCharAt(int position) {
    if (!isValidPosition(position)) {
        return;
    }
    
    shiftLeft(position, 1);
    length--;
    data[length] = '\0';
}

void DynamicString::appendChar(char ch) {
    ensureCapacity(length + 2);
    data[length] = ch;
    length++;
    data[length] = '\0';
}

void DynamicString::prependChar(char ch) {
    insertCharAt(0, ch);
}

// String Manipulation
void DynamicString::append(const char* str) {
    if (!str) {
        return;
    }
    
    int strLen = strlen(str);
    ensureCapacity(length + strLen + 1);
    strcat(data, str);
    length += strLen;
}

void DynamicString::append(const std::string& str) {
    append(str.c_str());
}

void DynamicString::prepend(const char* str) {
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

void DynamicString::prepend(const std::string& str) {
    prepend(str.c_str());
}

void DynamicString::insertAt(int position, const char* str) {
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

void DynamicString::insertAt(int position, const std::string& str) {
    insertAt(position, str.c_str());
}

void DynamicString::deleteAt(int position, int count) {
    if (position < 0 || position >= length || count <= 0) {
        return;
    }
    
    int actualCount = std::min(count, length - position);
    shiftLeft(position + actualCount, actualCount);
    length -= actualCount;
    data[length] = '\0';
}

void DynamicString::replace(const char* oldStr, const char* newStr) {
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

void DynamicString::replace(const std::string& oldStr, const std::string& newStr) {
    replace(oldStr.c_str(), newStr.c_str());
}

// String Search and Comparison
int DynamicString::find(const char* substr) const {
    if (!substr || length == 0) {
        return -1;
    }
    
    char* result = strstr(data, substr);
    return result ? result - data : -1;
}

int DynamicString::find(const std::string& substr) const {
    return find(substr.c_str());
}

int DynamicString::findLast(const char* substr) const {
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

int DynamicString::findLast(const std::string& substr) const {
    return findLast(substr.c_str());
}

int DynamicString::findChar(char ch) const {
    char* result = strchr(data, ch);
    return result ? result - data : -1;
}

int DynamicString::findLastChar(char ch) const {
    char* result = strrchr(data, ch);
    return result ? result - data : -1;
}

bool DynamicString::startsWith(const char* prefix) const {
    if (!prefix) {
        return false;
    }
    
    int prefixLen = strlen(prefix);
    if (prefixLen > length) {
        return false;
    }
    
    return strncmp(data, prefix, prefixLen) == 0;
}

bool DynamicString::startsWith(const std::string& prefix) const {
    return startsWith(prefix.c_str());
}

bool DynamicString::endsWith(const char* suffix) const {
    if (!suffix) {
        return false;
    }
    
    int suffixLen = strlen(suffix);
    if (suffixLen > length) {
        return false;
    }
    
    return strncmp(data + length - suffixLen, suffix, suffixLen) == 0;
}

bool DynamicString::endsWith(const std::string& suffix) const {
    return endsWith(suffix.c_str());
}

bool DynamicString::contains(const char* substr) const {
    return find(substr) != -1;
}

bool DynamicString::contains(const std::string& substr) const {
    return contains(substr.c_str());
}

int DynamicString::compare(const char* str) const {
    if (!str) {
        return length > 0 ? 1 : 0;
    }
    return strcmp(data, str);
}

int DynamicString::compare(const std::string& str) const {
    return compare(str.c_str());
}

int DynamicString::compare(const String& str) const {
    return compare(str.toCString());
}

bool DynamicString::equals(const char* str) const {
    return compare(str) == 0;
}

bool DynamicString::equals(const std::string& str) const {
    return equals(str.c_str());
}

bool DynamicString::equals(const String& str) const {
    return equals(str.toCString());
}

// String Transformation
void DynamicString::toUpperCase() {
    for (int i = 0; i < length; i++) {
        data[i] = toupper(data[i]);
    }
}

void DynamicString::toLowerCase() {
    for (int i = 0; i < length; i++) {
        data[i] = tolower(data[i]);
    }
}

void DynamicString::reverse() {
    for (int i = 0; i < length / 2; i++) {
        std::swap(data[i], data[length - 1 - i]);
    }
}

void DynamicString::trim() {
    trimLeft();
    trimRight();
}

void DynamicString::trimLeft() {
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

void DynamicString::trimRight() {
    int end = length - 1;
    while (end >= 0 && isspace(data[end])) {
        end--;
    }
    
    length = end + 1;
    data[length] = '\0';
}

void DynamicString::removeWhitespace() {
    int writePos = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(data[i])) {
            data[writePos++] = data[i];
        }
    }
    length = writePos;
    data[length] = '\0';
}

void DynamicString::removeDuplicates() {
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
String* DynamicString::substring(int start, int end) const {
    if (!isValidRange(start, end)) {
        return new DynamicString();
    }
    
    int subLen = end - start;
    DynamicString* result = new DynamicString();
    result->ensureCapacity(subLen + 1);
    strncpy(result->data, data + start, subLen);
    result->data[subLen] = '\0';
    result->length = subLen;
    
    return result;
}

String* DynamicString::substring(int start) const {
    return substring(start, length);
}

void DynamicString::extractSubstring(int start, int end, char* buffer) const {
    if (!buffer || !isValidRange(start, end)) {
        return;
    }
    
    int subLen = end - start;
    strncpy(buffer, data + start, subLen);
    buffer[subLen] = '\0';
}

void DynamicString::extractSubstring(int start, char* buffer) const {
    extractSubstring(start, length, buffer);
}

// String Analysis
int DynamicString::countOccurrences(const char* substr) const {
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

int DynamicString::countOccurrences(const std::string& substr) const {
    return countOccurrences(substr.c_str());
}

int DynamicString::countOccurrences(char ch) const {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == ch) {
            count++;
        }
    }
    return count;
}

int DynamicString::countWords() const {
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

int DynamicString::countLines() const {
    return countOccurrences('\n') + 1;
}

bool DynamicString::isNumeric() const {
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

bool DynamicString::isAlpha() const {
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

bool DynamicString::isAlphaNumeric() const {
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
std::string DynamicString::toString() const {
    return std::string(data);
}

const char* DynamicString::toCString() const {
    return data;
}

int DynamicString::toInt() const {
    return std::stoi(data);
}

double DynamicString::toDouble() const {
    return std::stod(data);
}

// Advanced Operations
void DynamicString::resize(int newSize) {
    if (newSize < 0) {
        return;
    }
    
    ensureCapacity(newSize + 1);
    length = newSize;
    data[length] = '\0';
}

void DynamicString::reserve(int newCapacity) {
    if (newCapacity > capacity) {
        ensureCapacity(newCapacity);
    }
}

void DynamicString::shrinkToFit() {
    if (length + 1 < capacity) {
        reallocate(length + 1);
    }
}

String* DynamicString::clone() const {
    return new DynamicString(*this);
}

void DynamicString::swap(String& other) {
    DynamicString* otherDynamic = dynamic_cast<DynamicString*>(&other);
    if (otherDynamic) {
        std::swap(data, otherDynamic->data);
        std::swap(length, otherDynamic->length);
        std::swap(capacity, otherDynamic->capacity);
    }
}

void DynamicString::concatenate(const String& other) {
    append(other.toCString());
}

void DynamicString::concatenate(const char* str) {
    append(str);
}

void DynamicString::concatenate(const std::string& str) {
    append(str);
}

// String Splitting and Joining
String** DynamicString::split(const char* delimiter) const {
    // TODO: Implement string splitting
    return nullptr;
}

String** DynamicString::split(const std::string& delimiter) const {
    return split(delimiter.c_str());
}

String** DynamicString::split(char delimiter) const {
    // TODO: Implement character splitting
    return nullptr;
}

String* DynamicString::join(const String* strings[], int count, const char* separator) const {
    // TODO: Implement string joining
    return nullptr;
}

String* DynamicString::join(const String* strings[], int count, const std::string& separator) const {
    return join(strings, count, separator.c_str());
}

// Pattern Matching
bool DynamicString::matches(const char* pattern) const {
    // TODO: Implement pattern matching
    return false;
}

bool DynamicString::matches(const std::string& pattern) const {
    return matches(pattern.c_str());
}

int DynamicString::findPattern(const char* pattern) const {
    // TODO: Implement pattern finding
    return -1;
}

int DynamicString::findPattern(const std::string& pattern) const {
    return findPattern(pattern.c_str());
}

void DynamicString::replacePattern(const char* pattern, const char* replacement) {
    // TODO: Implement pattern replacement
}

void DynamicString::replacePattern(const std::string& pattern, const std::string& replacement) {
    replacePattern(pattern.c_str(), replacement.c_str());
}

// Memory Management
void DynamicString::free() {
    delete[] data;
    data = nullptr;
    length = 0;
    capacity = 0;
}

// Operator overloads
DynamicString DynamicString::operator+(const DynamicString& other) const {
    DynamicString result = *this;
    result.append(other.data);
    return result;
}

DynamicString DynamicString::operator+(const char* str) const {
    DynamicString result = *this;
    result.append(str);
    return result;
}

DynamicString DynamicString::operator+(const std::string& str) const {
    DynamicString result = *this;
    result.append(str);
    return result;
}

DynamicString& DynamicString::operator+=(const DynamicString& other) {
    append(other.data);
    return *this;
}

DynamicString& DynamicString::operator+=(const char* str) {
    append(str);
    return *this;
}

DynamicString& DynamicString::operator+=(const std::string& str) {
    append(str);
    return *this;
}

char& DynamicString::operator[](int index) {
    return data[index];
}

const char& DynamicString::operator[](int index) const {
    return data[index];
}

// Helper methods
void DynamicString::ensureCapacity(int requiredCapacity) {
    if (requiredCapacity > capacity) {
        int newCapacity = capacity;
        while (newCapacity < requiredCapacity) {
            newCapacity *= GROWTH_FACTOR;
        }
        reallocate(newCapacity);
    }
}

void DynamicString::growCapacity() {
    reallocate(capacity * GROWTH_FACTOR);
}

void DynamicString::shrinkCapacity() {
    if (length < capacity / GROWTH_FACTOR) {
        reallocate(capacity / GROWTH_FACTOR);
    }
}

bool DynamicString::isValidPosition(int position) const {
    return position >= 0 && position < length;
}

bool DynamicString::isValidRange(int start, int end) const {
    return start >= 0 && start < length && end > start && end <= length;
}

void DynamicString::shiftRight(int position, int count) {
    for (int i = length - 1; i >= position; i--) {
        data[i + count] = data[i];
    }
}

void DynamicString::shiftLeft(int position, int count) {
    for (int i = position; i < length; i++) {
        data[i - count] = data[i];
    }
}

int DynamicString::calculateNewLength(const char* str) const {
    return strlen(str);
}

void DynamicString::copyString(const char* source, char* destination, int count) {
    strncpy(destination, source, count);
}

void DynamicString::reallocate(int newCapacity) {
    char* newData = new char[newCapacity];
    strcpy(newData, data);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

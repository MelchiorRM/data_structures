#include "StringBuffer.hpp"
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <mutex>
#include <functional>

// Constructor and Destructor
StringBuffer::StringBuffer() : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    data[0] = '\0';
}

StringBuffer::StringBuffer(const char* str) : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    createString(str);
}

StringBuffer::StringBuffer(const std::string& str) : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    createString(str);
}

StringBuffer::StringBuffer(int size) : length(0), capacity(INITIAL_CAPACITY) {
    data = new char[capacity];
    createString(size);
}

StringBuffer::StringBuffer(const StringBuffer& other) : length(other.length), capacity(other.capacity) {
    data = new char[capacity];
    strcpy(data, other.data);
}

StringBuffer::~StringBuffer() {
    delete[] data;
}

// Assignment operator
StringBuffer& StringBuffer::operator=(const StringBuffer& other) {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(bufferMutex);
        delete[] data;
        length = other.length;
        capacity = other.capacity;
        data = new char[capacity];
        strcpy(data, other.data);
    }
    return *this;
}

StringBuffer& StringBuffer::operator=(const char* str) {
    createString(str);
    return *this;
}

StringBuffer& StringBuffer::operator=(const std::string& str) {
    createString(str);
    return *this;
}

// Basic String Operations
void StringBuffer::createString(const char* str) {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

void StringBuffer::createString(const std::string& str) {
    createString(str.c_str());
}

void StringBuffer::createString(int size) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (size < 0) {
        size = 0;
    }
    
    ensureCapacity(size + 1);
    memset(data, '\0', size + 1);
    length = size;
}

void StringBuffer::display() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    std::cout << data;
}

void StringBuffer::clear() {
    std::lock_guard<std::mutex> lock(bufferMutex);
    length = 0;
    data[0] = '\0';
}

bool StringBuffer::isEmpty() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return length == 0;
}

int StringBuffer::getLength() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return length;
}

int StringBuffer::getCapacity() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return capacity;
}

// Character Operations
char StringBuffer::getCharAt(int position) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!isValidPosition(position)) {
        return '\0';
    }
    return data[position];
}

void StringBuffer::setCharAt(int position, char ch) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!isValidPosition(position)) {
        return;
    }
    data[position] = ch;
}

void StringBuffer::insertCharAt(int position, char ch) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (position < 0 || position > length) {
        return;
    }
    
    ensureCapacity(length + 2);
    shiftRight(position, 1);
    data[position] = ch;
    length++;
    data[length] = '\0';
}

void StringBuffer::deleteCharAt(int position) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!isValidPosition(position)) {
        return;
    }
    
    shiftLeft(position, 1);
    length--;
    data[length] = '\0';
}

void StringBuffer::appendChar(char ch) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    ensureCapacity(length + 2);
    data[length] = ch;
    length++;
    data[length] = '\0';
}

void StringBuffer::prependChar(char ch) {
    insertCharAt(0, ch);
}

// String Manipulation
void StringBuffer::append(const char* str) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!str) {
        return;
    }
    
    int strLen = strlen(str);
    ensureCapacity(length + strLen + 1);
    strcat(data, str);
    length += strLen;
}

void StringBuffer::append(const std::string& str) {
    append(str.c_str());
}

void StringBuffer::prepend(const char* str) {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

void StringBuffer::prepend(const std::string& str) {
    prepend(str.c_str());
}

void StringBuffer::insertAt(int position, const char* str) {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

void StringBuffer::insertAt(int position, const std::string& str) {
    insertAt(position, str.c_str());
}

void StringBuffer::deleteAt(int position, int count) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (position < 0 || position >= length || count <= 0) {
        return;
    }
    
    int actualCount = std::min(count, length - position);
    shiftLeft(position + actualCount, actualCount);
    length -= actualCount;
    data[length] = '\0';
}

void StringBuffer::replace(const char* oldStr, const char* newStr) {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

void StringBuffer::replace(const std::string& oldStr, const std::string& newStr) {
    replace(oldStr.c_str(), newStr.c_str());
}

// String Search and Comparison
int StringBuffer::find(const char* substr) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!substr || length == 0) {
        return -1;
    }
    
    char* result = strstr(data, substr);
    return result ? result - data : -1;
}

int StringBuffer::find(const std::string& substr) const {
    return find(substr.c_str());
}

int StringBuffer::findLast(const char* substr) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

int StringBuffer::findLast(const std::string& substr) const {
    return findLast(substr.c_str());
}

int StringBuffer::findChar(char ch) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    char* result = strchr(data, ch);
    return result ? result - data : -1;
}

int StringBuffer::findLastChar(char ch) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    char* result = strrchr(data, ch);
    return result ? result - data : -1;
}

bool StringBuffer::startsWith(const char* prefix) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!prefix) {
        return false;
    }
    
    int prefixLen = strlen(prefix);
    if (prefixLen > length) {
        return false;
    }
    
    return strncmp(data, prefix, prefixLen) == 0;
}

bool StringBuffer::startsWith(const std::string& prefix) const {
    return startsWith(prefix.c_str());
}

bool StringBuffer::endsWith(const char* suffix) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!suffix) {
        return false;
    }
    
    int suffixLen = strlen(suffix);
    if (suffixLen > length) {
        return false;
    }
    
    return strncmp(data + length - suffixLen, suffix, suffixLen) == 0;
}

bool StringBuffer::endsWith(const std::string& suffix) const {
    return endsWith(suffix.c_str());
}

bool StringBuffer::contains(const char* substr) const {
    return find(substr) != -1;
}

bool StringBuffer::contains(const std::string& substr) const {
    return contains(substr.c_str());
}

int StringBuffer::compare(const char* str) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!str) {
        return length > 0 ? 1 : 0;
    }
    return strcmp(data, str);
}

int StringBuffer::compare(const std::string& str) const {
    return compare(str.c_str());
}

int StringBuffer::compare(const String& str) const {
    return compare(str.toCString());
}

bool StringBuffer::equals(const char* str) const {
    return compare(str) == 0;
}

bool StringBuffer::equals(const std::string& str) const {
    return equals(str.c_str());
}

bool StringBuffer::equals(const String& str) const {
    return equals(str.toCString());
}

// String Transformation
void StringBuffer::toUpperCase() {
    std::lock_guard<std::mutex> lock(bufferMutex);
    for (int i = 0; i < length; i++) {
        data[i] = toupper(data[i]);
    }
}

void StringBuffer::toLowerCase() {
    std::lock_guard<std::mutex> lock(bufferMutex);
    for (int i = 0; i < length; i++) {
        data[i] = tolower(data[i]);
    }
}

void StringBuffer::reverse() {
    std::lock_guard<std::mutex> lock(bufferMutex);
    for (int i = 0; i < length / 2; i++) {
        std::swap(data[i], data[length - 1 - i]);
    }
}

void StringBuffer::trim() {
    std::lock_guard<std::mutex> lock(bufferMutex);
    trimLeft();
    trimRight();
}

void StringBuffer::trimLeft() {
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

void StringBuffer::trimRight() {
    int end = length - 1;
    while (end >= 0 && isspace(data[end])) {
        end--;
    }
    
    length = end + 1;
    data[length] = '\0';
}

void StringBuffer::removeWhitespace() {
    int writePos = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(data[i])) {
            data[writePos++] = data[i];
        }
    }
    length = writePos;
    data[length] = '\0';
}

void StringBuffer::removeDuplicates() {
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
String* StringBuffer::substring(int start, int end) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!isValidRange(start, end)) {
        return new StringBuffer();
    }
    
    int subLen = end - start;
    StringBuffer* result = new StringBuffer();
    result->ensureCapacity(subLen + 1);
    strncpy(result->data, data + start, subLen);
    result->data[subLen] = '\0';
    result->length = subLen;
    
    return result;
}

String* StringBuffer::substring(int start) const {
    return substring(start, length);
}

void StringBuffer::extractSubstring(int start, int end, char* buffer) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!buffer || !isValidRange(start, end)) {
        return;
    }
    
    int subLen = end - start;
    strncpy(buffer, data + start, subLen);
    buffer[subLen] = '\0';
}

void StringBuffer::extractSubstring(int start, char* buffer) const {
    extractSubstring(start, length, buffer);
}

// String Analysis
int StringBuffer::countOccurrences(const char* substr) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

int StringBuffer::countOccurrences(const std::string& substr) const {
    return countOccurrences(substr.c_str());
}

int StringBuffer::countOccurrences(char ch) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == ch) {
            count++;
        }
    }
    return count;
}

int StringBuffer::countWords() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

int StringBuffer::countLines() const {
    return countOccurrences('\n') + 1;
}

bool StringBuffer::isNumeric() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

bool StringBuffer::isAlpha() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
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

bool StringBuffer::isAlphaNumeric() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
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
std::string StringBuffer::toString() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return std::string(data);
}

const char* StringBuffer::toCString() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return data;
}

int StringBuffer::toInt() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return std::stoi(data);
}

double StringBuffer::toDouble() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return std::stod(data);
}

// Advanced Operations
void StringBuffer::resize(int newSize) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (newSize < 0) {
        return;
    }
    
    ensureCapacity(newSize + 1);
    length = newSize;
    data[length] = '\0';
}

void StringBuffer::reserve(int newCapacity) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (newCapacity > capacity) {
        ensureCapacity(newCapacity);
    }
}

void StringBuffer::shrinkToFit() {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (length + 1 < capacity) {
        reallocate(length + 1);
    }
}

String* StringBuffer::clone() const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return new StringBuffer(*this);
}

void StringBuffer::swap(String& other) {
    StringBuffer* otherBuffer = dynamic_cast<StringBuffer*>(&other);
    if (otherBuffer) {
        std::lock(bufferMutex, otherBuffer->bufferMutex);
        std::lock_guard<std::mutex> lock1(bufferMutex, std::adopt_lock);
        std::lock_guard<std::mutex> lock2(otherBuffer->bufferMutex, std::adopt_lock);
        
        std::swap(data, otherBuffer->data);
        std::swap(length, otherBuffer->length);
        std::swap(capacity, otherBuffer->capacity);
    }
}

void StringBuffer::concatenate(const String& other) {
    append(other.toCString());
}

void StringBuffer::concatenate(const char* str) {
    append(str);
}

void StringBuffer::concatenate(const std::string& str) {
    append(str);
}

// String Splitting and Joining
String** StringBuffer::split(const char* delimiter) const {
    // TODO: Implement string splitting
    return nullptr;
}

String** StringBuffer::split(const std::string& delimiter) const {
    return split(delimiter.c_str());
}

String** StringBuffer::split(char delimiter) const {
    // TODO: Implement character splitting
    return nullptr;
}

String* StringBuffer::join(const String* strings[], int count, const char* separator) const {
    // TODO: Implement string joining
    return nullptr;
}

String* StringBuffer::join(const String* strings[], int count, const std::string& separator) const {
    return join(strings, count, separator.c_str());
}

// Pattern Matching
bool StringBuffer::matches(const char* pattern) const {
    // TODO: Implement pattern matching
    return false;
}

bool StringBuffer::matches(const std::string& pattern) const {
    return matches(pattern.c_str());
}

int StringBuffer::findPattern(const char* pattern) const {
    // TODO: Implement pattern finding
    return -1;
}

int StringBuffer::findPattern(const std::string& pattern) const {
    return findPattern(pattern.c_str());
}

void StringBuffer::replacePattern(const char* pattern, const char* replacement) {
    // TODO: Implement pattern replacement
}

void StringBuffer::replacePattern(const std::string& pattern, const std::string& replacement) {
    replacePattern(pattern.c_str(), replacement.c_str());
}

// Memory Management
void StringBuffer::free() {
    std::lock_guard<std::mutex> lock(bufferMutex);
    delete[] data;
    data = nullptr;
    length = 0;
    capacity = 0;
}

// StringBuffer specific operations
void StringBuffer::appendBuffer(const StringBuffer& other) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    append(other.data);
}

void StringBuffer::appendBuffer(const char* str, int length) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!str || length <= 0) {
        return;
    }
    
    ensureCapacity(this->length + length + 1);
    strncat(data, str, length);
    this->length += length;
    data[this->length] = '\0';
}

void StringBuffer::prependBuffer(const StringBuffer& other) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    prepend(other.data);
}

void StringBuffer::prependBuffer(const char* str, int length) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!str || length <= 0) {
        return;
    }
    
    ensureCapacity(this->length + length + 1);
    shiftRight(0, length);
    strncpy(data, str, length);
    this->length += length;
    data[this->length] = '\0';
}

void StringBuffer::insertBufferAt(int position, const StringBuffer& other) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    insertAt(position, other.data);
}

void StringBuffer::insertBufferAt(int position, const char* str, int length) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    if (!str || length <= 0 || position < 0 || position > this->length) {
        return;
    }
    
    ensureCapacity(this->length + length + 1);
    shiftRight(position, length);
    strncpy(data + position, str, length);
    this->length += length;
    data[this->length] = '\0';
}

// Thread-safe operations
void StringBuffer::lock() const {
    bufferMutex.lock();
}

void StringBuffer::unlock() const {
    bufferMutex.unlock();
}

bool StringBuffer::tryLock() const {
    return bufferMutex.try_lock();
}

// Operator overloads
StringBuffer StringBuffer::operator+(const StringBuffer& other) const {
    StringBuffer result = *this;
    result.append(other.data);
    return result;
}

StringBuffer StringBuffer::operator+(const char* str) const {
    StringBuffer result = *this;
    result.append(str);
    return result;
}

StringBuffer StringBuffer::operator+(const std::string& str) const {
    StringBuffer result = *this;
    result.append(str);
    return result;
}

StringBuffer& StringBuffer::operator+=(const StringBuffer& other) {
    append(other.data);
    return *this;
}

StringBuffer& StringBuffer::operator+=(const char* str) {
    append(str);
    return *this;
}

StringBuffer& StringBuffer::operator+=(const std::string& str) {
    append(str);
    return *this;
}

char& StringBuffer::operator[](int index) {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return data[index];
}

const char& StringBuffer::operator[](int index) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    return data[index];
}

// Helper methods
void StringBuffer::ensureCapacity(int requiredCapacity) {
    if (requiredCapacity > capacity) {
        int newCapacity = capacity;
        while (newCapacity < requiredCapacity) {
            newCapacity *= GROWTH_FACTOR;
        }
        reallocate(newCapacity);
    }
}

void StringBuffer::growCapacity() {
    reallocate(capacity * GROWTH_FACTOR);
}

void StringBuffer::shrinkCapacity() {
    if (length < capacity / GROWTH_FACTOR) {
        reallocate(capacity / GROWTH_FACTOR);
    }
}

bool StringBuffer::isValidPosition(int position) const {
    return position >= 0 && position < length;
}

bool StringBuffer::isValidRange(int start, int end) const {
    return start >= 0 && start < length && end > start && end <= length;
}

void StringBuffer::shiftRight(int position, int count) {
    for (int i = length - 1; i >= position; i--) {
        data[i + count] = data[i];
    }
}

void StringBuffer::shiftLeft(int position, int count) {
    for (int i = position; i < length; i++) {
        data[i - count] = data[i];
    }
}

int StringBuffer::calculateNewLength(const char* str) const {
    return strlen(str);
}

void StringBuffer::copyString(const char* source, char* destination, int count) {
    strncpy(destination, source, count);
}

void StringBuffer::reallocate(int newCapacity) {
    char* newData = new char[newCapacity];
    strcpy(newData, data);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void StringBuffer::lockAndExecute(std::function<void()> operation) const {
    std::lock_guard<std::mutex> lock(bufferMutex);
    operation();
}

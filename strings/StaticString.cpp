#include "StaticString.hpp"
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>

// Constructor and Destructor
StaticString::StaticString() : length(0) {
    data = staticData;
    capacity = MAX_CAPACITY;
    data[0] = '\0';
}

StaticString::StaticString(const char* str) : length(0) {
    data = staticData;
    capacity = MAX_CAPACITY;
    createString(str);
}

StaticString::StaticString(const std::string& str) : length(0) {
    data = staticData;
    capacity = MAX_CAPACITY;
    createString(str);
}

StaticString::StaticString(int size) : length(0) {
    data = staticData;
    capacity = MAX_CAPACITY;
    createString(size);
}

StaticString::~StaticString() {
    // No dynamic memory to free for static string
}

// Basic String Operations
void StaticString::createString(const char* str) {
    if (!str) {
        length = 0;
        data[0] = '\0';
        return;
    }
    
    int strLen = strlen(str);
    if (strLen >= capacity) {
        strLen = capacity - 1; // Leave space for null terminator
    }
    
    strncpy(data, str, strLen);
    data[strLen] = '\0';
    length = strLen;
}

void StaticString::createString(const std::string& str) {
    createString(str.c_str());
}

void StaticString::createString(int size) {
    if (size < 0 || size >= capacity) {
        size = 0;
    }
    
    memset(data, '\0', size + 1);
    length = size;
}

void StaticString::display() const {
    std::cout << data;
}

void StaticString::clear() {
    length = 0;
    data[0] = '\0';
}

bool StaticString::isEmpty() const {
    return length == 0;
}

int StaticString::getLength() const {
    return length;
}

int StaticString::getCapacity() const {
    return capacity;
}

// Character Operations
char StaticString::getCharAt(int position) const {
    if (!isValidPosition(position)) {
        return '\0';
    }
    return data[position];
}

void StaticString::setCharAt(int position, char ch) {
    if (!isValidPosition(position)) {
        return;
    }
    data[position] = ch;
}

void StaticString::insertCharAt(int position, char ch) {
    if (length >= capacity - 1 || position < 0 || position > length) {
        return;
    }
    
    shiftRight(position, 1);
    data[position] = ch;
    length++;
    data[length] = '\0';
}

void StaticString::deleteCharAt(int position) {
    if (!isValidPosition(position)) {
        return;
    }
    
    shiftLeft(position, 1);
    length--;
    data[length] = '\0';
}

void StaticString::appendChar(char ch) {
    if (length < capacity - 1) {
        data[length] = ch;
        length++;
        data[length] = '\0';
    }
}

void StaticString::prependChar(char ch) {
    insertCharAt(0, ch);
}

// String Manipulation
void StaticString::append(const char* str) {
    if (!str || length >= capacity - 1) {
        return;
    }
    
    int strLen = strlen(str);
    int availableSpace = capacity - length - 1;
    int copyLen = std::min(strLen, availableSpace);
    
    strncat(data, str, copyLen);
    length += copyLen;
}

void StaticString::append(const std::string& str) {
    append(str.c_str());
}

void StaticString::prepend(const char* str) {
    if (!str) {
        return;
    }
    
    int strLen = strlen(str);
    if (strLen + length >= capacity) {
        return; // Not enough space
    }
    
    shiftRight(0, strLen);
    strncpy(data, str, strLen);
    length += strLen;
    data[length] = '\0';
}

void StaticString::prepend(const std::string& str) {
    prepend(str.c_str());
}

void StaticString::insertAt(int position, const char* str) {
    if (!str || position < 0 || position > length) {
        return;
    }
    
    int strLen = strlen(str);
    if (strLen + length >= capacity) {
        return; // Not enough space
    }
    
    shiftRight(position, strLen);
    strncpy(data + position, str, strLen);
    length += strLen;
    data[length] = '\0';
}

void StaticString::insertAt(int position, const std::string& str) {
    insertAt(position, str.c_str());
}

void StaticString::deleteAt(int position, int count) {
    if (position < 0 || position >= length || count <= 0) {
        return;
    }
    
    int actualCount = std::min(count, length - position);
    shiftLeft(position + actualCount, actualCount);
    length -= actualCount;
    data[length] = '\0';
}

void StaticString::replace(const char* oldStr, const char* newStr) {
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

void StaticString::replace(const std::string& oldStr, const std::string& newStr) {
    replace(oldStr.c_str(), newStr.c_str());
}

// String Search and Comparison
int StaticString::find(const char* substr) const {
    if (!substr || length == 0) {
        return -1;
    }
    
    char* result = strstr(data, substr);
    return result ? result - data : -1;
}

int StaticString::find(const std::string& substr) const {
    return find(substr.c_str());
}

int StaticString::findLast(const char* substr) const {
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

int StaticString::findLast(const std::string& substr) const {
    return findLast(substr.c_str());
}

int StaticString::findChar(char ch) const {
    char* result = strchr(data, ch);
    return result ? result - data : -1;
}

int StaticString::findLastChar(char ch) const {
    char* result = strrchr(data, ch);
    return result ? result - data : -1;
}

bool StaticString::startsWith(const char* prefix) const {
    if (!prefix) {
        return false;
    }
    
    int prefixLen = strlen(prefix);
    if (prefixLen > length) {
        return false;
    }
    
    return strncmp(data, prefix, prefixLen) == 0;
}

bool StaticString::startsWith(const std::string& prefix) const {
    return startsWith(prefix.c_str());
}

bool StaticString::endsWith(const char* suffix) const {
    if (!suffix) {
        return false;
    }
    
    int suffixLen = strlen(suffix);
    if (suffixLen > length) {
        return false;
    }
    
    return strncmp(data + length - suffixLen, suffix, suffixLen) == 0;
}

bool StaticString::endsWith(const std::string& suffix) const {
    return endsWith(suffix.c_str());
}

bool StaticString::contains(const char* substr) const {
    return find(substr) != -1;
}

bool StaticString::contains(const std::string& substr) const {
    return contains(substr.c_str());
}

int StaticString::compare(const char* str) const {
    if (!str) {
        return length > 0 ? 1 : 0;
    }
    return strcmp(data, str);
}

int StaticString::compare(const std::string& str) const {
    return compare(str.c_str());
}

int StaticString::compare(const String& str) const {
    return compare(str.toCString());
}

bool StaticString::equals(const char* str) const {
    return compare(str) == 0;
}

bool StaticString::equals(const std::string& str) const {
    return equals(str.c_str());
}

bool StaticString::equals(const String& str) const {
    return equals(str.toCString());
}

// String Transformation
void StaticString::toUpperCase() {
    for (int i = 0; i < length; i++) {
        data[i] = toupper(data[i]);
    }
}

void StaticString::toLowerCase() {
    for (int i = 0; i < length; i++) {
        data[i] = tolower(data[i]);
    }
}

void StaticString::reverse() {
    for (int i = 0; i < length / 2; i++) {
        std::swap(data[i], data[length - 1 - i]);
    }
}

void StaticString::trim() {
    trimLeft();
    trimRight();
}

void StaticString::trimLeft() {
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

void StaticString::trimRight() {
    int end = length - 1;
    while (end >= 0 && isspace(data[end])) {
        end--;
    }
    
    length = end + 1;
    data[length] = '\0';
}

void StaticString::removeWhitespace() {
    int writePos = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(data[i])) {
            data[writePos++] = data[i];
        }
    }
    length = writePos;
    data[length] = '\0';
}

void StaticString::removeDuplicates() {
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
String* StaticString::substring(int start, int end) const {
    if (!isValidRange(start, end)) {
        return new StaticString();
    }
    
    int subLen = end - start;
    StaticString* result = new StaticString();
    result->createString(subLen);
    strncpy(result->data, data + start, subLen);
    result->data[subLen] = '\0';
    result->length = subLen;
    
    return result;
}

String* StaticString::substring(int start) const {
    return substring(start, length);
}

void StaticString::extractSubstring(int start, int end, char* buffer) const {
    if (!buffer || !isValidRange(start, end)) {
        return;
    }
    
    int subLen = end - start;
    strncpy(buffer, data + start, subLen);
    buffer[subLen] = '\0';
}

void StaticString::extractSubstring(int start, char* buffer) const {
    extractSubstring(start, length, buffer);
}

// String Analysis
int StaticString::countOccurrences(const char* substr) const {
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

int StaticString::countOccurrences(const std::string& substr) const {
    return countOccurrences(substr.c_str());
}

int StaticString::countOccurrences(char ch) const {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == ch) {
            count++;
        }
    }
    return count;
}

int StaticString::countWords() const {
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

int StaticString::countLines() const {
    return countOccurrences('\n') + 1;
}

bool StaticString::isNumeric() const {
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

bool StaticString::isAlpha() const {
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

bool StaticString::isAlphaNumeric() const {
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
std::string StaticString::toString() const {
    return std::string(data);
}

const char* StaticString::toCString() const {
    return data;
}

int StaticString::toInt() const {
    return std::stoi(data);
}

double StaticString::toDouble() const {
    return std::stod(data);
}

// Advanced Operations
void StaticString::resize(int newSize) {
    if (newSize < 0 || newSize >= capacity) {
        return;
    }
    
    length = newSize;
    data[length] = '\0';
}

void StaticString::reserve(int newCapacity) {
    // Static string capacity cannot be changed
    // This method is kept for interface compatibility
}

void StaticString::shrinkToFit() {
    // Static string capacity cannot be changed
    // This method is kept for interface compatibility
}

String* StaticString::clone() const {
    return new StaticString(data);
}

void StaticString::swap(String& other) {
    StaticString* otherStatic = dynamic_cast<StaticString*>(&other);
    if (otherStatic) {
        std::swap(data, otherStatic->data);
        std::swap(length, otherStatic->length);
        std::swap(capacity, otherStatic->capacity);
    }
}

void StaticString::concatenate(const String& other) {
    append(other.toCString());
}

void StaticString::concatenate(const char* str) {
    append(str);
}

void StaticString::concatenate(const std::string& str) {
    append(str);
}

// String Splitting and Joining
String** StaticString::split(const char* delimiter) const {
    // TODO: Implement string splitting
    return nullptr;
}

String** StaticString::split(const std::string& delimiter) const {
    return split(delimiter.c_str());
}

String** StaticString::split(char delimiter) const {
    // TODO: Implement character splitting
    return nullptr;
}

String* StaticString::join(const String* strings[], int count, const char* separator) const {
    // TODO: Implement string joining
    return nullptr;
}

String* StaticString::join(const String* strings[], int count, const std::string& separator) const {
    return join(strings, count, separator.c_str());
}

// Pattern Matching
bool StaticString::matches(const char* pattern) const {
    // TODO: Implement pattern matching
    return false;
}

bool StaticString::matches(const std::string& pattern) const {
    return matches(pattern.c_str());
}

int StaticString::findPattern(const char* pattern) const {
    // TODO: Implement pattern finding
    return -1;
}

int StaticString::findPattern(const std::string& pattern) const {
    return findPattern(pattern.c_str());
}

void StaticString::replacePattern(const char* pattern, const char* replacement) {
    // TODO: Implement pattern replacement
}

void StaticString::replacePattern(const std::string& pattern, const std::string& replacement) {
    replacePattern(pattern.c_str(), replacement.c_str());
}

// Memory Management
void StaticString::free() {
    clear();
}

// Helper methods
bool StaticString::isValidPosition(int position) const {
    return position >= 0 && position < length;
}

bool StaticString::isValidRange(int start, int end) const {
    return start >= 0 && start < length && end > start && end <= length;
}

void StaticString::shiftRight(int position, int count) {
    for (int i = length - 1; i >= position; i--) {
        if (i + count < capacity) {
            data[i + count] = data[i];
        }
    }
}

void StaticString::shiftLeft(int position, int count) {
    for (int i = position; i < length; i++) {
        data[i - count] = data[i];
    }
}

int StaticString::calculateNewLength(const char* str) const {
    return strlen(str);
}

void StaticString::copyString(const char* source, char* destination, int count) {
    strncpy(destination, source, count);
}

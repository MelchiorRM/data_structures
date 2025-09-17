#ifndef STATIC_STRING_HPP
#define STATIC_STRING_HPP

#include "String.hpp"

/**
 * StaticString - Fixed-size string implementation
 * Memory allocated at compile time with maximum capacity
 * Fast access but limited flexibility
 * Maximum capacity: 1000 characters
 */
class StaticString : public String {
private:
    static const int MAX_CAPACITY = 1000;
    char staticData[MAX_CAPACITY];

public:
    // Constructor and Destructor
    StaticString();
    StaticString(const char* str);
    StaticString(const std::string& str);
    StaticString(int size);
    ~StaticString() override;

    // Basic String Operations
    void createString(const char* str) override;
    void createString(const std::string& str) override;
    void createString(int size) override;
    void display() const override;
    void clear() override;
    bool isEmpty() const override;
    int getLength() const override;
    int getCapacity() const override;

    // Character Operations
    char getCharAt(int position) const override;
    void setCharAt(int position, char ch) override;
    void insertCharAt(int position, char ch) override;
    void deleteCharAt(int position) override;
    void appendChar(char ch) override;
    void prependChar(char ch) override;

    // String Manipulation
    void append(const char* str) override;
    void append(const std::string& str) override;
    void prepend(const char* str) override;
    void prepend(const std::string& str) override;
    void insertAt(int position, const char* str) override;
    void insertAt(int position, const std::string& str) override;
    void deleteAt(int position, int count) override;
    void replace(const char* oldStr, const char* newStr) override;
    void replace(const std::string& oldStr, const std::string& newStr) override;

    // String Search and Comparison
    int find(const char* substr) const override;
    int find(const std::string& substr) const override;
    int findLast(const char* substr) const override;
    int findLast(const std::string& substr) const override;
    int findChar(char ch) const override;
    int findLastChar(char ch) const override;
    bool startsWith(const char* prefix) const override;
    bool startsWith(const std::string& prefix) const override;
    bool endsWith(const char* suffix) const override;
    bool endsWith(const std::string& suffix) const override;
    bool contains(const char* substr) const override;
    bool contains(const std::string& substr) const override;
    int compare(const char* str) const override;
    int compare(const std::string& str) const override;
    int compare(const String& str) const override;
    bool equals(const char* str) const override;
    bool equals(const std::string& str) const override;
    bool equals(const String& str) const override;

    // String Transformation
    void toUpperCase() override;
    void toLowerCase() override;
    void reverse() override;
    void trim() override;
    void trimLeft() override;
    void trimRight() override;
    void removeWhitespace() override;
    void removeDuplicates() override;

    // Substring Operations
    String* substring(int start, int end) const override;
    String* substring(int start) const override;
    void extractSubstring(int start, int end, char* buffer) const override;
    void extractSubstring(int start, char* buffer) const override;

    // String Analysis
    int countOccurrences(const char* substr) const override;
    int countOccurrences(const std::string& substr) const override;
    int countOccurrences(char ch) const override;
    int countWords() const override;
    int countLines() const override;
    bool isNumeric() const override;
    bool isAlpha() const override;
    bool isAlphaNumeric() const override;

    // String Conversion
    std::string toString() const override;
    const char* toCString() const override;
    int toInt() const override;
    double toDouble() const override;

    // Advanced Operations
    void resize(int newSize) override;
    void reserve(int newCapacity) override;
    void shrinkToFit() override;
    String* clone() const override;
    void swap(String& other) override;
    void concatenate(const String& other) override;
    void concatenate(const char* str) override;
    void concatenate(const std::string& str) override;

    // String Splitting and Joining
    String** split(const char* delimiter) const override;
    String** split(const std::string& delimiter) const override;
    String** split(char delimiter) const override;
    String* join(const String* strings[], int count, const char* separator) const override;
    String* join(const String* strings[], int count, const std::string& separator) const override;

    // Pattern Matching
    bool matches(const char* pattern) const override;
    bool matches(const std::string& pattern) const override;
    int findPattern(const char* pattern) const override;
    int findPattern(const std::string& pattern) const override;
    void replacePattern(const char* pattern, const char* replacement) override;
    void replacePattern(const std::string& pattern, const std::string& replacement) override;

    // Memory Management
    void free() override;

private:
    // Helper methods
    bool isValidPosition(int position) const;
    bool isValidRange(int start, int end) const;
    void shiftRight(int position, int count);
    void shiftLeft(int position, int count);
    int calculateNewLength(const char* str) const;
    void copyString(const char* source, char* destination, int count);
};

#endif // STATIC_STRING_HPP

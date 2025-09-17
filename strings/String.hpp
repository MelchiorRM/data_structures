#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

/**
 * Abstract base class for string data structures
 * Defines the common interface for all string implementations
 */
class String {
protected:
    char* data;
    int length;
    int capacity;

public:
    // Constructor and Destructor
    String();
    virtual ~String() = 0;

    // Basic String Operations
    virtual void createString(const char* str) = 0;
    virtual void createString(const std::string& str) = 0;
    virtual void createString(int size) = 0;
    virtual void display() const = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual int getCapacity() const = 0;

    // Character Operations
    virtual char getCharAt(int position) const = 0;
    virtual void setCharAt(int position, char ch) = 0;
    virtual void insertCharAt(int position, char ch) = 0;
    virtual void deleteCharAt(int position) = 0;
    virtual void appendChar(char ch) = 0;
    virtual void prependChar(char ch) = 0;

    // String Manipulation
    virtual void append(const char* str) = 0;
    virtual void append(const std::string& str) = 0;
    virtual void prepend(const char* str) = 0;
    virtual void prepend(const std::string& str) = 0;
    virtual void insertAt(int position, const char* str) = 0;
    virtual void insertAt(int position, const std::string& str) = 0;
    virtual void deleteAt(int position, int count) = 0;
    virtual void replace(const char* oldStr, const char* newStr) = 0;
    virtual void replace(const std::string& oldStr, const std::string& newStr) = 0;

    // String Search and Comparison
    virtual int find(const char* substr) const = 0;
    virtual int find(const std::string& substr) const = 0;
    virtual int findLast(const char* substr) const = 0;
    virtual int findLast(const std::string& substr) const = 0;
    virtual int findChar(char ch) const = 0;
    virtual int findLastChar(char ch) const = 0;
    virtual bool startsWith(const char* prefix) const = 0;
    virtual bool startsWith(const std::string& prefix) const = 0;
    virtual bool endsWith(const char* suffix) const = 0;
    virtual bool endsWith(const std::string& suffix) const = 0;
    virtual bool contains(const char* substr) const = 0;
    virtual bool contains(const std::string& substr) const = 0;
    virtual int compare(const char* str) const = 0;
    virtual int compare(const std::string& str) const = 0;
    virtual int compare(const String& str) const = 0;
    virtual bool equals(const char* str) const = 0;
    virtual bool equals(const std::string& str) const = 0;
    virtual bool equals(const String& str) const = 0;

    // String Transformation
    virtual void toUpperCase() = 0;
    virtual void toLowerCase() = 0;
    virtual void reverse() = 0;
    virtual void trim() = 0;
    virtual void trimLeft() = 0;
    virtual void trimRight() = 0;
    virtual void removeWhitespace() = 0;
    virtual void removeDuplicates() = 0;

    // Substring Operations
    virtual String* substring(int start, int end) const = 0;
    virtual String* substring(int start) const = 0;
    virtual void extractSubstring(int start, int end, char* buffer) const = 0;
    virtual void extractSubstring(int start, char* buffer) const = 0;

    // String Analysis
    virtual int countOccurrences(const char* substr) const = 0;
    virtual int countOccurrences(const std::string& substr) const = 0;
    virtual int countOccurrences(char ch) const = 0;
    virtual int countWords() const = 0;
    virtual int countLines() const = 0;
    virtual bool isNumeric() const = 0;
    virtual bool isAlpha() const = 0;
    virtual bool isAlphaNumeric() const = 0;

    // String Conversion
    virtual std::string toString() const = 0;
    virtual const char* toCString() const = 0;
    virtual int toInt() const = 0;
    virtual double toDouble() const = 0;

    // Advanced Operations
    virtual void resize(int newSize) = 0;
    virtual void reserve(int newCapacity) = 0;
    virtual void shrinkToFit() = 0;
    virtual String* clone() const = 0;
    virtual void swap(String& other) = 0;
    virtual void concatenate(const String& other) = 0;
    virtual void concatenate(const char* str) = 0;
    virtual void concatenate(const std::string& str) = 0;

    // String Splitting and Joining
    virtual String** split(const char* delimiter) const = 0;
    virtual String** split(const std::string& delimiter) const = 0;
    virtual String** split(char delimiter) const = 0;
    virtual String* join(const String* strings[], int count, const char* separator) const = 0;
    virtual String* join(const String* strings[], int count, const std::string& separator) const = 0;

    // Pattern Matching
    virtual bool matches(const char* pattern) const = 0;
    virtual bool matches(const std::string& pattern) const = 0;
    virtual int findPattern(const char* pattern) const = 0;
    virtual int findPattern(const std::string& pattern) const = 0;
    virtual void replacePattern(const char* pattern, const char* replacement) = 0;
    virtual void replacePattern(const std::string& pattern, const std::string& replacement) = 0;

    // Memory Management
    virtual void free() = 0;
};

#endif // STRING_HPP

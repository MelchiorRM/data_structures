# String Data Structures

This directory contains implementations of various string data structures in C++. All implementations follow a common interface defined in `String.hpp`.

## String Types

### 1. Static String (`StaticString.hpp`, `StaticString.cpp`)
- Fixed-size string with maximum capacity
- Memory allocated at compile time
- Fast access but limited flexibility
- Maximum capacity: 1000 characters
- Ideal for strings with known maximum length

### 2. Dynamic String (`DynamicString.hpp`, `DynamicString.cpp`)
- Resizable string with dynamic memory allocation
- Grows and shrinks as needed
- More memory overhead but flexible
- Similar to std::string functionality
- Automatic memory management

### 3. String Buffer (`StringBuffer.hpp`, `StringBuffer.cpp`)
- Thread-safe string buffer implementation
- Optimized for frequent string concatenation operations
- Uses internal buffer with automatic resizing
- Thread-safe operations for concurrent access
- Ideal for multi-threaded applications

### 4. String Builder (`StringBuilder.hpp`, `StringBuilder.cpp`)
- Optimized string builder for frequent concatenation
- Uses internal buffer with efficient memory management
- Optimized for building strings through multiple append operations
- Similar to Java's StringBuilder or C#'s StringBuilder
- Additional line-based operations

## Common Interface

All string types implement the following operations:

### Basic String Operations
- `createString(const char* str)` - Create from C-string
- `createString(const std::string& str)` - Create from std::string
- `createString(int size)` - Create string of specific size
- `display()` - Print string contents
- `clear()` - Clear string
- `isEmpty()` - Check if empty
- `getLength()` - Get current length
- `getCapacity()` - Get current capacity

### Character Operations
- `getCharAt(int position)` - Get character at position
- `setCharAt(int position, char ch)` - Set character at position
- `insertCharAt(int position, char ch)` - Insert character at position
- `deleteCharAt(int position)` - Delete character at position
- `appendChar(char ch)` - Append character
- `prependChar(char ch)` - Prepend character

### String Manipulation
- `append(const char* str)` - Append C-string
- `append(const std::string& str)` - Append std::string
- `prepend(const char* str)` - Prepend C-string
- `prepend(const std::string& str)` - Prepend std::string
- `insertAt(int position, const char* str)` - Insert string at position
- `insertAt(int position, const std::string& str)` - Insert std::string at position
- `deleteAt(int position, int count)` - Delete substring
- `replace(const char* oldStr, const char* newStr)` - Replace substring
- `replace(const std::string& oldStr, const std::string& newStr)` - Replace std::string

### String Search and Comparison
- `find(const char* substr)` - Find substring
- `find(const std::string& substr)` - Find std::string
- `findLast(const char* substr)` - Find last occurrence
- `findLast(const std::string& substr)` - Find last occurrence
- `findChar(char ch)` - Find character
- `findLastChar(char ch)` - Find last character
- `startsWith(const char* prefix)` - Check if starts with prefix
- `startsWith(const std::string& prefix)` - Check if starts with prefix
- `endsWith(const char* suffix)` - Check if ends with suffix
- `endsWith(const std::string& suffix)` - Check if ends with suffix
- `contains(const char* substr)` - Check if contains substring
- `contains(const std::string& substr)` - Check if contains substring
- `compare(const char* str)` - Compare with C-string
- `compare(const std::string& str)` - Compare with std::string
- `compare(const String& str)` - Compare with String object
- `equals(const char* str)` - Check equality with C-string
- `equals(const std::string& str)` - Check equality with std::string
- `equals(const String& str)` - Check equality with String object

### String Transformation
- `toUpperCase()` - Convert to uppercase
- `toLowerCase()` - Convert to lowercase
- `reverse()` - Reverse string
- `trim()` - Trim whitespace from both ends
- `trimLeft()` - Trim whitespace from left
- `trimRight()` - Trim whitespace from right
- `removeWhitespace()` - Remove all whitespace
- `removeDuplicates()` - Remove consecutive duplicates

### Substring Operations
- `substring(int start, int end)` - Get substring
- `substring(int start)` - Get substring from start to end
- `extractSubstring(int start, int end, char* buffer)` - Extract to buffer
- `extractSubstring(int start, char* buffer)` - Extract to buffer

### String Analysis
- `countOccurrences(const char* substr)` - Count substring occurrences
- `countOccurrences(const std::string& substr)` - Count substring occurrences
- `countOccurrences(char ch)` - Count character occurrences
- `countWords()` - Count words
- `countLines()` - Count lines
- `isNumeric()` - Check if numeric
- `isAlpha()` - Check if alphabetic
- `isAlphaNumeric()` - Check if alphanumeric

### String Conversion
- `toString()` - Convert to std::string
- `toCString()` - Convert to C-string
- `toInt()` - Convert to integer
- `toDouble()` - Convert to double

### Advanced Operations
- `resize(int newSize)` - Resize string
- `reserve(int newCapacity)` - Reserve capacity
- `shrinkToFit()` - Shrink to fit
- `clone()` - Create copy
- `swap(String& other)` - Swap contents
- `concatenate(const String& other)` - Concatenate with String
- `concatenate(const char* str)` - Concatenate with C-string
- `concatenate(const std::string& str)` - Concatenate with std::string

### String Splitting and Joining
- `split(const char* delimiter)` - Split by delimiter
- `split(const std::string& delimiter)` - Split by delimiter
- `split(char delimiter)` - Split by character
- `join(const String* strings[], int count, const char* separator)` - Join strings
- `join(const String* strings[], int count, const std::string& separator)` - Join strings

### Pattern Matching
- `matches(const char* pattern)` - Check if matches pattern
- `matches(const std::string& pattern)` - Check if matches pattern
- `findPattern(const char* pattern)` - Find pattern
- `findPattern(const std::string& pattern)` - Find pattern
- `replacePattern(const char* pattern, const char* replacement)` - Replace pattern
- `replacePattern(const std::string& pattern, const std::string& replacement)` - Replace pattern

### Memory Management
- `free()` - Free memory

## Type-Specific Operations

### StringBuffer Specific
- `appendBuffer(const StringBuffer& other)` - Append StringBuffer
- `appendBuffer(const char* str, int length)` - Append with length
- `prependBuffer(const StringBuffer& other)` - Prepend StringBuffer
- `prependBuffer(const char* str, int length)` - Prepend with length
- `insertBufferAt(int position, const StringBuffer& other)` - Insert StringBuffer
- `insertBufferAt(int position, const char* str, int length)` - Insert with length
- `lock()` - Lock for thread safety
- `unlock()` - Unlock
- `tryLock()` - Try to lock

### StringBuilder Specific
- `appendLine(const char* str)` - Append string with newline
- `appendLine(const std::string& str)` - Append std::string with newline
- `appendLine()` - Append newline
- `appendFormat(const char* format, ...)` - Append formatted string
- `appendNumber(int number)` - Append integer
- `appendNumber(double number)` - Append double
- `appendNumber(long number)` - Append long
- `insertLineAt(int position, const char* str)` - Insert line at position
- `insertLineAt(int position, const std::string& str)` - Insert line at position
- `insertLineAt(int position)` - Insert newline at position
- `replaceLine(int lineNumber, const char* str)` - Replace line
- `replaceLine(int lineNumber, const std::string& str)` - Replace line
- `deleteLine(int lineNumber)` - Delete line
- `insertAtLine(int lineNumber, const char* str)` - Insert at line
- `insertAtLine(int lineNumber, const std::string& str)` - Insert at line
- `ensureBufferCapacity(int requiredCapacity)` - Ensure buffer capacity
- `optimizeBuffer()` - Optimize buffer
- `flushBuffer()` - Flush buffer
- `getBufferSize()` - Get buffer size

## Usage

Compile and run the main program:
```bash
g++ -o string_demo main.cpp StaticString.cpp DynamicString.cpp StringBuffer.cpp StringBuilder.cpp -std=c++11 -pthread
./string_demo
```

## Implementation Status

⚠️ **Some methods are currently stubs with TODO comments.** The following features need implementation:

### Not Yet Implemented
- String splitting and joining operations
- Pattern matching operations
- Some advanced string analysis functions

### Fully Implemented
- Basic string operations
- Character operations
- String manipulation
- String search and comparison
- String transformation
- Substring operations
- String analysis (basic)
- String conversion
- Memory management
- Type-specific operations

## File Structure

```
strings/
├── String.hpp                    # Base abstract class
├── StaticString.hpp/.cpp         # Static string implementation
├── DynamicString.hpp/.cpp        # Dynamic string implementation
├── StringBuffer.hpp/.cpp         # String buffer implementation
├── StringBuilder.hpp/.cpp        # String builder implementation
├── main.cpp                      # Interactive demo program
└── README.md                     # This file
```

## Performance Characteristics

### StaticString
- **Memory**: Fixed allocation, no dynamic memory
- **Access**: O(1) for character access
- **Modification**: O(n) for insertions/deletions
- **Capacity**: Limited to 1000 characters
- **Use Case**: Known maximum length strings

### DynamicString
- **Memory**: Dynamic allocation with growth factor
- **Access**: O(1) for character access
- **Modification**: O(n) for insertions/deletions, O(1) amortized for appends
- **Capacity**: Grows as needed
- **Use Case**: General-purpose string operations

### StringBuffer
- **Memory**: Dynamic allocation with thread safety
- **Access**: O(1) for character access (with locking)
- **Modification**: O(n) for insertions/deletions, O(1) amortized for appends
- **Capacity**: Grows as needed
- **Use Case**: Multi-threaded applications

### StringBuilder
- **Memory**: Dynamic allocation optimized for concatenation
- **Access**: O(1) for character access
- **Modification**: O(n) for insertions/deletions, O(1) amortized for appends
- **Capacity**: Grows as needed with buffer optimization
- **Use Case**: Frequent string building operations

## Next Steps

1. Implement string splitting and joining operations
2. Add pattern matching functionality
3. Implement advanced string analysis functions
4. Add unit tests for all implementations
5. Optimize performance for specific use cases
6. Add more string manipulation utilities
7. Implement string formatting operations
8. Add support for different character encodings

## Thread Safety

- **StaticString**: Not thread-safe
- **DynamicString**: Not thread-safe
- **StringBuffer**: Thread-safe (all operations are protected by mutex)
- **StringBuilder**: Not thread-safe

## Memory Management

All string implementations use RAII (Resource Acquisition Is Initialization) principles:
- Memory is automatically managed
- Destructors properly clean up resources
- Copy constructors and assignment operators are properly implemented
- The `free()` method can be called explicitly if needed

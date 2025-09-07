# Array Data Structures

This directory contains implementations of various array data structures in C++. All implementations follow a common interface defined in `Array.hpp`.

## Array Types

### 1. Static Array (`StaticArray.hpp`, `StaticArray.cpp`)
- Fixed-size array with maximum capacity
- Memory allocated at compile time
- Fast access but limited flexibility
- Maximum size: 1000 elements

### 2. Dynamic Array (`DynamicArray.hpp`, `DynamicArray.cpp`)
- Resizable array with dynamic memory allocation
- Grows and shrinks as needed
- More memory overhead but flexible
- Similar to std::vector functionality

### 3. Circular Array (`CircularArray.hpp`, `CircularArray.cpp`)
- Array with circular buffer behavior
- Efficient for queue-like operations
- Front and rear pointers for rotation
- Fixed capacity with wraparound

### 4. Multidimensional Array (`MultidimensionalArray.hpp`, `MultidimensionalArray.cpp`)
- Support for 2D, 3D, and N-dimensional arrays
- Row-major storage with linear indexing
- Matrix operations and transformations
- Sub-array extraction and manipulation

### 5. Jagged Array (`JaggedArray.hpp`, `JaggedArray.cpp`)
- Array of arrays with different row sizes
- Memory efficient for irregular data
- Row-based operations and manipulation
- Dynamic row addition/removal

## Common Interface

All array types implement the following operations:

### Basic Operations
- `insertAtBeginning(int value)` - Insert at start
- `insertAtEnd(int value)` - Insert at end
- `insertAtPosition(int value, int position)` - Insert at specific position
- `deleteAtBeginning()` - Delete from start
- `deleteAtEnd()` - Delete from end
- `deleteAtPosition(int position)` - Delete from specific position
- `createArray(int size)` - Initialize array
- `display()` - Print array contents
- `search(int value)` - Find element
- `updateAtPosition(int position, int newValue)` - Update at position
- `updateValue(int oldValue, int newValue)` - Update by value

### Advanced Operations
- `reverse()` - Reverse array
- `findMiddle()` - Get middle element
- `removeDuplicates()` - Remove duplicates
- `swapElements(int pos1, int pos2)` - Swap elements
- `getSize()` - Get current size
- `sort()` - Sort array
- `clone()` - Create copy
- `compare(const Array& other)` - Compare arrays
- `mergeSorted(const Array& other)` - Merge sorted arrays
- `concatenate(const Array& other)` - Append arrays
- `intersection(const Array& other)` - Find common elements
- `unionWith(const Array& other)` - Combine unique elements
- `difference(const Array& other)` - Find different elements
- `alternateMerge(const Array& other)` - Alternate merge
- `swapContents(Array& other)` - Swap array contents
- `clear()` - Clear array
- `isEmpty()` - Check if empty
- `getElementAt(int position)` - Get element at position
- `resize(int newSize)` - Resize array

## Usage

Compile and run the main program:
```bash
g++ -o array_demo main.cpp StaticArray.cpp DynamicArray.cpp CircularArray.cpp MultidimensionalArray.cpp JaggedArray.cpp
./array_demo
```

## Implementation Status

⚠️ **All methods are currently stubs with TODO comments.** You need to implement the actual functionality for each method in the `.cpp` files.

## File Structure

```
arrays/
├── Array.hpp                    # Base abstract class
├── StaticArray.hpp/.cpp         # Static array implementation
├── DynamicArray.hpp/.cpp        # Dynamic array implementation
├── CircularArray.hpp/.cpp       # Circular array implementation
├── MultidimensionalArray.hpp/.cpp # Multidimensional array implementation
├── JaggedArray.hpp/.cpp         # Jagged array implementation
├── main.cpp                     # Interactive demo program
└── README.md                    # This file
```

## Next Steps

1. Implement the basic operations for each array type
2. Add error handling and bounds checking
3. Implement advanced operations
4. Add unit tests
5. Optimize performance where needed

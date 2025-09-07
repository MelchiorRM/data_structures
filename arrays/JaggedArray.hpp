#ifndef JAGGEDARRAY_HPP
#define JAGGEDARRAY_HPP

#include "Array.hpp"
#include <vector>

class JaggedArray : public Array {
    private:
        int** data;                    // Array of pointers to rows
        int* rowSizes;                 // Size of each row
        int numRows;                   // Number of rows
        int totalElements;             // Total number of elements across all rows
        int maxRowSize;                // Maximum row size
        
    public:
        JaggedArray();
        JaggedArray(int numRows);
        JaggedArray(const std::vector<int>& rowSizes);
        ~JaggedArray();
        
        // Basic operations (adapted for jagged array)
        void insertAtBeginning(int value) override;
        void insertAtEnd(int value) override;
        void insertAtPosition(int value, int position) override;
        void deleteAtBeginning() override;
        void deleteAtEnd() override;
        void deleteAtPosition(int position) override;
        void createArray(int size) override;
        void display() const override;
        bool search(int value) const override;
        void updateAtPosition(int position, int newValue) override;
        void updateValue(int oldValue, int newValue) override;
        void reverse() override;
        int findMiddle() const override;
        void removeDuplicates() override;
        void swapElements(int pos1, int pos2) override;
        int getSize() const override;
        void sort() override;
        
        // Advanced operations
        JaggedArray* clone() const override;
        bool compare(const Array& other) const override;
        JaggedArray* mergeSorted(const Array& other) const override;
        void concatenate(const Array& other) override;
        JaggedArray* intersection(const Array& other) const override;
        JaggedArray* unionWith(const Array& other) const override;
        JaggedArray* difference(const Array& other) const override;
        JaggedArray* alternateMerge(const Array& other) const override;
        void swapContents(Array& other) override;
        void clear() override;
        bool isEmpty() const override;
        int getElementAt(int position) const override;
        void resize(int newSize) override;
        
        // Jagged array specific methods
        void setElement(int row, int col, int value);
        int getElement(int row, int col) const;
        
        void createJaggedArray(int numRows);
        void createJaggedArray(const std::vector<int>& rowSizes);
        void displayJagged() const;
        
        int getNumRows() const;
        int getRowSize(int row) const;
        int getMaxRowSize() const;
        int getMinRowSize() const;
        
        void addRow(int size);
        void addRow(const std::vector<int>& values);
        void removeRow(int row);
        void insertRow(int position, int size);
        void insertRow(int position, const std::vector<int>& values);
        
        void resizeRow(int row, int newSize);
        void expandRow(int row, int additionalSize);
        void shrinkRow(int row, int reduceSize);
        
        void fillRow(int row, int value);
        void fillRow(int row, const std::vector<int>& values);
        void fillAll(int value);
        
        std::vector<int> getRow(int row) const;
        std::vector<int> getColumn(int col) const;
        std::vector<int> getAllElements() const;
        
        void setRow(int row, const std::vector<int>& values);
        void setColumn(int col, const std::vector<int>& values);
        
        void sortRow(int row);
        void sortAllRows();
        void sortByRowSize();
        void sortByRowSum();
        
        JaggedArray* getSubArray(int startRow, int endRow) const;
        void copySubArray(const JaggedArray& source, int startRow, int destRow);
        
        void transpose();
        void reverseRows();
        void reverseColumns();
        void reverseAll();
        
        void rotateRows(int steps);
        void rotateColumns(int steps);
        
        bool isValidIndex(int row, int col) const;
        int getLinearIndex(int row, int col) const;
        void getIndicesFromLinear(int linearIndex, int& row, int& col) const;
        
        void compact();  // Remove empty rows and optimize memory
        void expand();   // Add empty rows to make it more uniform
        
        int getTotalElements() const;
        int getEmptyRows() const;
        double getAverageRowSize() const;
        
        void mergeRows(int row1, int row2);
        void splitRow(int row, int splitPosition);
        
        JaggedArray* flatten() const;  // Convert to 1D array
        void unflatten(const std::vector<int>& values, const std::vector<int>& rowSizes);
        
        void swapRows(int row1, int row2);
        void moveRow(int fromRow, int toRow);
        
        void balanceRows();  // Try to make rows more equal in size
        void randomizeRowSizes(int minSize, int maxSize);
        
        std::vector<std::vector<int> >toVector() const;
        void fromVector(const std::vector<std::vector<int> >& vec);
};

#endif

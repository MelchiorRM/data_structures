#ifndef MULTIDIMENSIONALARRAY_HPP
#define MULTIDIMENSIONALARRAY_HPP

#include "Array.hpp"
#include <vector>

class MultidimensionalArray : public Array {
    private:
        int** data;
        int* dimensions;        // Array storing size of each dimension
        int numDimensions;      // Number of dimensions (2D, 3D, etc.)
        int totalElements;      // Total number of elements
        int* currentSize;       // Current size of each dimension
        
    public:
        MultidimensionalArray();
        MultidimensionalArray(int rows, int cols);
        MultidimensionalArray(int dim1, int dim2, int dim3);
        MultidimensionalArray(int* dims, int numDims);
        ~MultidimensionalArray();
        
        // Basic operations (adapted for multidimensional)
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
        MultidimensionalArray* clone() const override;
        bool compare(const Array& other) const override;
        MultidimensionalArray* mergeSorted(const Array& other) const override;
        void concatenate(const Array& other) override;
        MultidimensionalArray* intersection(const Array& other) const override;
        MultidimensionalArray* unionWith(const Array& other) const override;
        MultidimensionalArray* difference(const Array& other) const override;
        MultidimensionalArray* alternateMerge(const Array& other) const override;
        void swapContents(Array& other) override;
        void clear() override;
        bool isEmpty() const override;
        int getElementAt(int position) const override;
        void resize(int newSize) override;
        
        // Multidimensional array specific methods
        void setElement(int row, int col, int value);
        void setElement(int x, int y, int z, int value);
        void setElement(int* indices, int value);
        int getElement(int row, int col) const;
        int getElement(int x, int y, int z) const;
        int getElement(int* indices) const;
        
        void create2DArray(int rows, int cols);
        void create3DArray(int x, int y, int z);
        void createNDArray(int* dimensions, int numDims);
        
        void display2D() const;
        void display3D() const;
        void displayND() const;
        
        int getRows() const;
        int getCols() const;
        int getDepth() const;
        int getDimension(int dim) const;
        int getNumDimensions() const;
        
        void transpose2D();
        void rotate2D(int degrees);
        void flip2D(bool horizontal, bool vertical);
        
        void fillRow(int row, int value);
        void fillCol(int col, int value);
        void fillLayer(int layer, int value);
        
        std::vector<int> getRow(int row) const;
        std::vector<int> getCol(int col) const;
        std::vector<int> getLayer(int layer) const;
        
        void setRow(int row, const std::vector<int>& values);
        void setCol(int col, const std::vector<int>& values);
        void setLayer(int layer, const std::vector<int>& values);
        
        MultidimensionalArray* getSubArray(int startRow, int endRow, int startCol, int endCol) const;
        void copySubArray(const MultidimensionalArray& source, int startRow, int startCol);
        
        void resize2D(int newRows, int newCols);
        void resize3D(int newX, int newY, int newZ);
        void resizeND(int* newDimensions, int numDims);
        
        bool isValidIndex(int row, int col) const;
        bool isValidIndex(int x, int y, int z) const;
        bool isValidIndex(int* indices) const;
        
        int getLinearIndex(int row, int col) const;
        int getLinearIndex(int x, int y, int z) const;
        int getLinearIndex(int* indices) const;
        
        void getIndicesFromLinear(int linearIndex, int& row, int& col) const;
        void getIndicesFromLinear(int linearIndex, int& x, int& y, int& z) const;
        void getIndicesFromLinear(int linearIndex, int* indices) const;
};

#endif

#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    int dataSize;
    int theCapacity;
    T *objects;
    const int SPARE_CAPACITY = 4;

public:
    typedef T *iterator;
    Vector(int initSize = 0)
    {
        dataSize = initSize;
        theCapacity = initSize + SPARE_CAPACITY;
        objects = new T[theCapacity];
    }

    ~Vector()
    {
        delete[] objects;
    }

    void reserve(int newCapacity) // we will resize the array
    // all we do is that we make a new array  and copy the elements in  it
    {
        if (newCapacity < dataSize) //  if we have for example 4 elements amd we use 2 then we will not need to  make resize
            return;

        T *oldArray = objects; // we will save the old array

        objects = new T[newCapacity];
        for (int k = 0; k < dataSize; k++)
            objects[k] = oldArray[k];

        theCapacity = newCapacity;

        delete[] oldArray;
    }

    T &operator[](int index) // we use v[10] instead of object.v[10]
    {
        return objects[index];
    }

    bool empty() const
    {
        return size() == 0;
    }

    int size() const
    {
        return dataSize;
    }

    int capacity() const
    {
        return theCapacity;
    }

    void push_back(const T &x)
    {
        if (dataSize == theCapacity)
            reserve(2 * theCapacity);
        objects[dataSize] = x;
        dataSize++;
        D
    }

    T pop_back()
    {
        T tmp = objects[dataSize - 1];
        dataSize--;
        return tmp;
    }

    iterator begin()
    {
        return &objects[0];
    }
    iterator end()
    {
        return &objects[size() - 1];
    }
};

int main()
{
    Vector<double> v;

    for (int i = 0; i < 20; i++)
        v.push_back(i);
    for (int i = 0; i < 20; i++)
        cout << v[i] << ", ";
    cout << endl;

    for (Vector<double>::iterator itr = v.begin(); itr <= v.end(); itr++)
        cout << *itr << ", ";

    cout << endl;

    return 0;
}

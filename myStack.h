#ifndef H_StackType
#define H_StackType 
#endif 
#include <iostream>
using namespace std;

template <class Type>
class stackType
{
private:
    int maxStackSize;
    int stacktop; //index of the top element in stack.
    Type* list;  // point to array which stors element.
public:
    void initializeStack();
    bool isEmptyStack();
    bool isFullStack();
    void destroyStack();
    void push(const Type& newItem);
    void pop(Type& poppedItem);
    void displaystack();
    Type top();
    stackType(int stackSize = 100);
    ~stackType();
    const stackType<Type>& operator=(const stackType<Type>&);
    stackType(const stackType<Type>& otherStack);
};
template<class Type>
void stackType<Type>::initializeStack()
{
    stacktop =0 ;
}
template <class Type>
void stackType<Type>::destroyStack()
{
    stacktop = 0;
}
template<class Type>
bool stackType<Type>::isEmptyStack()
{
    return(stacktop == 0);
}

template<class Type>
bool stackType<Type>::isFullStack()
{
    return(stacktop == maxStackSize);
}    // like 100==100
template<class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "The size of the array to hold the stack must"
            << "be positive. " << endl;
        cout << "Creating an array of size 100." << endl;
    }
    else  maxStackSize = stackSize;
    stacktop = 0;  // index 0 becuses array
    list = new Type[maxStackSize];
}
template<class Type>
stackType<Type>::~stackType()
{
    delete[] list;
}
template<class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    int j;
    maxStackSize = otherStack.maxStackSize;
    stacktop = otherStack.stacktop;
    list = new Type[maxStackSize];

    if (stacktop != 0)
        for (j = 0; j < stacktop; j++)
            list[j] = otherStack.list[j];
}

template<class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack)
{
    int j;

    if (this != &otherStack)
    {
        if (maxStackSize != otherStack.maxStackSize)
            cout << "Cannot copy. The two stacks are of "
            << "different sizes." << endl;
        else
        {
            stacktop = otherStack.stacktop;

            if (stacktop != 0)
                for (j = 0; j < stacktop; j++)

                    list[j] = otherStack.list[j];
        }
    }
    return *this;
}

template<class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    { // stacktop=0 in begaining
     
        list[stacktop] = newItem;
        stacktop++;
    }
    else
        cout << "Cannot add to a full stack." << endl;
}
template<class Type>
void stackType<Type>::pop(Type& poppedItem)
{
    if (!isEmptyStack())
    {
        stacktop--;
        poppedItem = list[stacktop] << endl;
        cout << poppedItem;//store in stacktop
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}


template<class Type>
void stackType<Type>::displaystack()
{
    int i;
    for (i = 0; i <stacktop; i++)
        cout << list[i] << " ";
    cout << endl;
}
template <class Type>
Type stackType<Type>::top()
{
    assert(stacktop != 0);

    return list[stacktop - 1];
}

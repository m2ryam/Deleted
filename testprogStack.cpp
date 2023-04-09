#include <iostream>
#include <assert.h>
#include "myStack.h"
using namespace std;

void testCopyConstructor(stackType<int> otherStack);

int main()
{
    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);
    int x;

    stack.push(66);
    stack.push(33);
    stack.push(88);
    stack.push(55);

    cout << "display the contants of Stack\n";
    cout << "from first element to last " << endl;
    stack.displaystack();
    cout << "\nThe Top Element in the Stack is " << stack.top();
    cout << endl;


    cout << "\n display the contants of Stack \n";
    cout << "from last element to first \n";
    cout << "with the using of POP function " << endl;

    while (!stack.isEmptyStack())
    {
        stack.pop(x);
      cout << " " << x;
     
   }

   

   copyStack = stack;
   while (!copyStack.isEmptyStack())
    {
       copyStack.pop(x);
        cout << "Inside copyStack " <<x << endl;
    }
    copyStack = stack;
    testCopyConstructor(stack);

    if (!stack.isEmptyStack())
    {
        cout << "Original stack is not empty" << endl;
        stack.pop(x);
        cout << "Top element of the original stack :" << x << endl;
   }
    dummyStack = stack;

    system("pause");
    return 0;
}
void testCopyConstructor(stackType<int> otherStack)
{
    int x;

    if (!otherStack.isEmptyStack())
    {
        cout << "Other stack is not empty" << endl;
        otherStack.pop(x);
    }
}
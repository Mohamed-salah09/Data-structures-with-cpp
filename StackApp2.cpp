#include <iostream>
#include <vector>
using namespace std;

template <typename t>
class Stack
{
private:
    vector<t> arr;

public:
    void push(t value)
    {
        arr.push_back(value);
    }

    bool isempty()
    {
        return arr.empty();
    }

    t pop()
    {
        if (isempty())
        {
            cout << "Stack is empty!\n";
            exit(1); // safer than returning invalid value
        }
        t val = arr.back();
        arr.pop_back();
        return val;
    }

    t peek()
    {
        if (isempty())
        {
            cout << "Stack is empty!\n";
            exit(1);
        }
        return arr.back();
    }

    int get_size()
    {
        return arr.size();
    }

    void display()
    {
        if (isempty())
        {
            cout << "Stack is empty!\n";
            return;
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
        cout << endl;
    }

    void clear()
    {
        arr.clear();
    }

    bool contains(t key)
    {
        for (t value : arr)
        {
            if (value == key)
                return true;
        }
        return false;
    }
};

string bigint_add(string num1, string num2)
{
    Stack<int> number1;
    Stack<int> number2;
    Stack<int> result;

    // push digits in reverse order
    for (int i = num1.length() - 1; i >= 0; i--)
        number1.push(num1[i] - '0');

    for (int i = num2.length() - 1; i >= 0; i--)
        number2.push(num2[i] - '0');

    int carry = 0;

    while (!number1.isempty() || !number2.isempty() || carry)
    {
        int digit1 = 0, digit2 = 0;

        if (!number1.isempty())
            digit1 = number1.pop();

        if (!number2.isempty())
            digit2 = number2.pop();

        int total = digit1 + digit2 + carry;
        carry = total / 10;

        result.push(total % 10);
    }

    string res = "";

    // build result
    while (!result.isempty())
    {
        res += to_string(result.pop());
    }

    return res;
}

int main()
{
    string num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    string result = bigint_add(num1, num2);

    cout << "Result = " << result << endl;

    return 0;
}
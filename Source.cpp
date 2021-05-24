#include "other.h"

#include <stdexcept>
#include <iostream>
#include <Windows.h>

using namespace std;

class MyEmptyException {};

class MyException
{
private:

    const char* error_;

public:

    MyException(const char* error) : error_(error) {}

    const char* what()
    {
        return error_;
    }
};

class Exception : public exception
{
private:

    const char* error_;

public:

    Exception(const char* error) : error_(error) {}

    const char* what() const noexcept
    {
        return error_;
    }
};

void myTerminate()
{
    cout << "Обробник вийняткових ситуацій відстутній.";
}

void myUnexpected()
{
    cout << "Обробник вийняткових ситуацій відстутній.";
}

template<typename T = int>
T input(const char* text)
{
    T result;
    cout << text;
    cin >> result;
    cout << '\n';
    clearCin();
    return result;
}

void task()
{
    const double eps = 0.00001;
    double a, b;
    int flag = 0;
    do
    {
        a = input<double>("Введіть a: ");
        b = input<double>("Введіть b: ");
        flag = input("Меню:\n1. Без специфікації;\n2. Із специфікацією throw();\n3. Із стандартною "
            "специфікацією;\n4. Із незалежною пустою специфікацією;\n5. Із незалежною специфікацією;\n"
            "6. Із унаслідованою специфікацією;\n0. Вихід;\nВведіть опцію: ");
        try
        {
            switch (flag)
            {
            case 0:
                break;
            case 1:
                cout << "Корінь: " << -b / a << "\n\n";
                break;
            case 2:
                if (abs(a) < eps)
                {
                    throw exception("Номер 2. Ділити на нуль неможна.\n\n");
                }
                else
                {
                    cout << "Корінь: " << -b / a << "\n\n";
                }
                break;
            case 3:
                if (abs(a) < eps)
                {
                    throw invalid_argument("Номер 3. Ділити на нуль неможна.\n\n");
                }
                else
                {
                    cout << "Корінь: " << -b / a << "\n\n";
                }
                break;
            case 4:
                if (abs(a) < eps)
                {
                    throw MyEmptyException();
                }
                else
                {
                    cout << "Корінь: " << -b / a << "\n\n";
                }
                break;
            case 5:
                if (abs(a) < eps)
                {
                    throw MyException("Номер 5. Ділити на нуль неможна.\n\n");
                }
                else
                {
                    cout << "Корінь: " << -b / a << "\n\n";
                }
                break;
            case 6:
                if (abs(a) < eps)
                {
                    throw Exception("Номер 6. Ділити на нуль неможна.\n\n");
                }
                else
                {
                    cout << "Корінь: " << -b / a << "\n\n";
                }
                break;
            default:
                cout << "Некоректне введення, спробуйте ще.\n\n";
                break;
            }
        }
        catch (exception& e)
        {
            cout << e.what();
        }
        catch (MyEmptyException& e)
        {
            cout << "Номер 4. Ділити на нуль не можна.\n\n";
        }
        catch (MyException& e)
        {
            cout << e.what();
        }
    } while (flag != 0);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitle(L"Лабораторна робота №5.2");
    set_terminate(myTerminate);
    set_unexpected(myUnexpected);
    task();
}
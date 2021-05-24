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
    cout << "�������� ����������� �������� ��������.";
}

void myUnexpected()
{
    cout << "�������� ����������� �������� ��������.";
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
        a = input<double>("������ a: ");
        b = input<double>("������ b: ");
        flag = input("����:\n1. ��� ������������;\n2. �� ������������� throw();\n3. �� ����������� "
            "�������������;\n4. �� ���������� ������ �������������;\n5. �� ���������� �������������;\n"
            "6. �� ������������ �������������;\n0. �����;\n������ �����: ");
        try
        {
            switch (flag)
            {
            case 0:
                break;
            case 1:
                cout << "�����: " << -b / a << "\n\n";
                break;
            case 2:
                if (abs(a) < eps)
                {
                    throw exception("����� 2. ĳ���� �� ���� �������.\n\n");
                }
                else
                {
                    cout << "�����: " << -b / a << "\n\n";
                }
                break;
            case 3:
                if (abs(a) < eps)
                {
                    throw invalid_argument("����� 3. ĳ���� �� ���� �������.\n\n");
                }
                else
                {
                    cout << "�����: " << -b / a << "\n\n";
                }
                break;
            case 4:
                if (abs(a) < eps)
                {
                    throw MyEmptyException();
                }
                else
                {
                    cout << "�����: " << -b / a << "\n\n";
                }
                break;
            case 5:
                if (abs(a) < eps)
                {
                    throw MyException("����� 5. ĳ���� �� ���� �������.\n\n");
                }
                else
                {
                    cout << "�����: " << -b / a << "\n\n";
                }
                break;
            case 6:
                if (abs(a) < eps)
                {
                    throw Exception("����� 6. ĳ���� �� ���� �������.\n\n");
                }
                else
                {
                    cout << "�����: " << -b / a << "\n\n";
                }
                break;
            default:
                cout << "���������� ��������, ��������� ��.\n\n";
                break;
            }
        }
        catch (exception& e)
        {
            cout << e.what();
        }
        catch (MyEmptyException& e)
        {
            cout << "����� 4. ĳ���� �� ���� �� �����.\n\n";
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
    SetConsoleTitle(L"����������� ������ �5.2");
    set_terminate(myTerminate);
    set_unexpected(myUnexpected);
    task();
}
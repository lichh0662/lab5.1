

#include <iostream>
#include "Lab51.h"
#include <ctime>

using namespace std;


int main()
{
    srand((unsigned)time(0));
    int row_arr, col_arr, num = 1;
    int numtask = 1;
    int choice = 0;

    cout << "Number of rows = ";
    cin >> row_arr;
    cout << "Number of columns = ";
    cin >> col_arr;

    Matrix MatrA(row_arr, col_arr);
    Matrix MatrB(row_arr, col_arr);

    while (numtask != 0) {
        cout << "\n\nChoose number of task\n";
        cout << "1. AutoInput matrix\n" << "2. Output rows\n" << "3. Output columns\n"
            << "4. Manual Input matrix\n" << "5. Output matrix\n" << "6. Get element of matrix\n"
            << "7. Trace of matrix\n" << "8. Summing of matrices\n" << "9. Multiplication of matrices\n"
            << "10. Multiplication of matrix to number\n" << "11. Det of matrix\n" << "Default. Clear console\n" << "0. Exit\n\n";
        cin >> numtask;
        switch (numtask)
        {
        case 1:
            cout << "Enter 1. Number of rows = ";
            cin >> row_arr;
            cout << "2. Number of columns = ";
            cin >> col_arr;
            cout << "For 1st or 2nd matrix?\n";
            cin >> choice;
            if (choice == 1)
                MatrA.auto_input(row_arr, col_arr);
            else MatrB.auto_input(row_arr, col_arr);
            break;
        case 2:
            cout << "MatrA.get_rows() = " << MatrA.get_rows() << endl;
            break;
        case 3:
            cout << "MatrA.get_columns() = " << MatrA.get_columns() << endl;
            break;
        case 4:
            cout << "1. Common Matrix;\n2. Square Matrix.\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter: 1. Number of rows = ";
                cin >> row_arr;
                cout << "2. Number of columns = ";
                cin >> col_arr;
                MatrA.input(row_arr, col_arr);
            }
            else
            {
                cout << "Enter 1. Number of rows and columns: ";
                cin >> row_arr;
                MatrA.input(row_arr);
            }
            break;
        case 5:
            MatrA.print();
            MatrB.print();
            break;
        case 6:
            cout << "Enter 1. Number of rows = ";
            cin >> row_arr;
            cout << "2. Number of columns = ";
            cin >> col_arr;
            cout << "MatrA.get_elem(" << row_arr << ", " << col_arr << ") = "
                << MatrA.get_elem(row_arr, col_arr) << endl;
            break;
        case 7:
            cout << "MatrA.trace() = " << MatrA.trace() << endl;
            cout << "Output the matrix?\n1: yes;\t0: no;\n";
            cin >> choice;
            if (choice == 1)
                MatrA.print();
            break;
        case 8:
            MatrA.sum(MatrB);
            break;
        case 9:
            MatrA.mult(MatrB);
            break;
        case 10:
            cout << "Enter number for multiplication\n";
            cin >> num;
            MatrA.mult_by_num(num);
            cout << "Output the matrix?\n1: yes;\t0: no;\n";
            cin >> choice;
            if (choice == 1)
                MatrA.print();
            break;
        case 11:
            MatrA.det();
            break;
        case 12:
            MatrA.check_memory();
            MatrB.check_memory();
            break;
        default: system("cls");
            break;
        }
    }
}

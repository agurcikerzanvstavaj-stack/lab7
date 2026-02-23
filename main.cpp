#include <iostream>
using namespace std;

const int MAX = 100;

// --------------------------------------------------
// Введення матриці
// --------------------------------------------------
void input_matrix(int matr[MAX][MAX], int &m, int &n)
{
    cout << "Enter number of rows (m): ";
    cin >> m;

    cout << "Enter number of columns (n): ";
    cin >> n;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "matr[" << i << "][" << j << "] = ";
            cin >> matr[i][j];
        }
    }
}

// --------------------------------------------------
// Вивід матриці
// --------------------------------------------------
void print_matrix(int matr[MAX][MAX], int m, int n)
{
    cout << "\nMatrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }
}

// --------------------------------------------------
// Task 1 – Сума головної діагоналі
// --------------------------------------------------
int diag_sum(int matr[MAX][MAX], int m, int n)
{
    int sm = 0;

    for (int i = 0; i < m; i++)
    {
        if (i < n)  // щоб не вийти за межі
            sm += matr[i][i];
    }

    return sm;
}

// --------------------------------------------------
// Видалення рядка
// --------------------------------------------------
void remove_row(int matr[MAX][MAX], int &m, int n, int index)
{
    if (index >= m)
    {
        cout << "Error! Row index must be < m\n";
        return;
    }

    for (int i = index + 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i - 1][j] = matr[i][j];
        }
    }

    m--;
}

// --------------------------------------------------
// Task 2 – Видалення рядків з від’ємними числами
// --------------------------------------------------
void change_matrix(int matr[MAX][MAX], int &m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matr[i][j] < 0)
            {
                remove_row(matr, m, n, i);
                i--;  // перевіряємо новий рядок
                break;
            }
        }
    }
}

// --------------------------------------------------
// Меню
// --------------------------------------------------
int main()
{
    int matr[MAX][MAX];
    int m = 0, n = 0;
    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1 - Task 1 (Sum of main diagonal)\n";
        cout << "2 - Task 2 (Remove rows with negative elements)\n";
        cout << "0 - Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                input_matrix(matr, m, n);
                print_matrix(matr, m, n);
                cout << "\nSum of main diagonal = "
                     << diag_sum(matr, m, n) << endl;
                break;

            case 2:
                input_matrix(matr, m, n);
                print_matrix(matr, m, n);
                change_matrix(matr, m, n);
                cout << "\nMatrix after removing rows with negative elements:\n";
                print_matrix(matr, m, n);
                break;

            case 0:
                cout << "Program finished.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

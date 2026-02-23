#include <iostream>
using namespace std;

const int MAX = 100;

// --------------------------------------------------
// 1. Сума головної діагоналі
// --------------------------------------------------
int diag_sum(int matr[MAX][MAX], int m, int n)
{
    int sm = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sm += matr[i][j];
            }
        }
    }

    return sm;
}

// --------------------------------------------------
// 2. Видалення рядка
// --------------------------------------------------
void remove_row(int matr[MAX][MAX], int &m, int n, int index)
{
    if (index >= m)
    {
        cout << "Error! Row index must be < m" << endl;
        return;
    }

    for (int i = index + 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i - 1][j] = matr[i][j];
        }
    }

    m--; // зменшуємо кількість рядків
}

// --------------------------------------------------
// 3. Зміна матриці (видалення рядків з від’ємними)
// --------------------------------------------------
void change_matr(int matr[MAX][MAX], int &m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matr[i][j] < 0)
            {
                remove_row(matr, m, n, i);
                i--; // щоб перевірити новий рядок на цьому місці
                break;
            }
        }
    }
}

// --------------------------------------------------
// Вивід матриці
// --------------------------------------------------
void print_matr(int matr[MAX][MAX], int m, int n)
{
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
// Головна функція
// --------------------------------------------------
int main()
{
    int matr[MAX][MAX];
    int m, n;

    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matr[i][j];

    cout << "\nMatrix:\n";
    print_matr(matr, m, n);

    // Сума діагоналі
    int sum = diag_sum(matr, m, n);
    cout << "\nSum of main diagonal: " << sum << endl;

    // Зміна матриці
    change_matr(matr, m, n);

    cout << "\nMatrix after removing rows with negative elements:\n";
    print_matr(matr, m, n);

    return 0;
}

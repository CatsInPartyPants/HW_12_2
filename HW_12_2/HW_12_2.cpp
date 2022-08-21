#include <iostream>
#include <Windows.h>

using namespace std;

const int row = 5;
const int col = 5;

const int len = 4;

//task 1

//functions for set int, double, char matrix
void set_matrix(int (&arr)[row][col]);
void set_matrix(double (&arr)[row][col]);
void set_matrix(char (&arr)[row][col]);

//functions for show int, double, char matrix
void show_matrix(int (&arr)[row][col]);
void show_matrix(double (&arr)[row][col]);
void show_matrix(char (&arr)[row][col]);

//functions for search min and max on the main diagonal of the matrix
void matrix_min_max(int (&arr)[row][col]);
void matrix_min_max(double (&arr)[row][col]);

//functions for sort every string in matrix
void sort_matrix(int(&arr)[row][col]);
void sort_matrix(double(&arr)[row][col]);


//task2

int greatest_common_divisor(int, int);

//task 3

void computer_guess(int* arr, int len);
void user_guess_number(int* arr, int len);
void game(int* comp_arr, int* user_arr, int len);



int main()
{   
    //task 1
    int int_matrix[row][col];
    set_matrix(int_matrix);
    show_matrix(int_matrix);
    cout << endl;
    matrix_min_max(int_matrix);
    cout << endl;
    cout << "after sorting:\n";
    sort_matrix(int_matrix);
    show_matrix(int_matrix);
    cout << endl;
    cout << endl;

    Sleep(1000);
    double double_matrix[row][col];
    set_matrix(double_matrix);
    show_matrix(double_matrix);
    cout << endl;
    matrix_min_max(double_matrix);
    cout << endl;
    cout << endl;
    cout << "after sorting:\n";
    sort_matrix(double_matrix);
    show_matrix(double_matrix);
    cout << endl;

    Sleep(1000);
    char char_matrix[row][col];
    set_matrix(char_matrix);
    show_matrix(char_matrix);
    cout << endl;

    //task 2

    int first, second;
    cout << "Enter first number->";
    cin >> first;
    cout << "Enter second number->";
    cin >> second;

    cout << "Greates common divisor for " << first << " and " << second << " is " << greatest_common_divisor(first, second);
    

    //task 3

    srand(time(NULL));
    int computer_number[4];
    int user_guess[4];
    cout << "computer guessing the number...\n";
    Sleep(2000);
    cout << "Done. The number have 4 digits. Try to gues it->";
    computer_guess(computer_number, len);
    cout << endl;
    game(computer_number, user_guess, len);
    

}

//task 1

void set_matrix(int (&arr)[row][col])
{
    srand(time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

void set_matrix(double(&arr)[row][col])
{
    srand(time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = (double) (rand() % 100)/3.2;
        }
    }
}

void set_matrix(char(&arr)[row][col])
{
    srand(time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = (char)(97 + rand() % 122);
        }
    }
}

void show_matrix(int(&arr)[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void show_matrix(double(&arr)[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void show_matrix(char(&arr)[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

void matrix_min_max(int(&arr)[row][col])
{
    int min = arr[0][0];
    int max = arr[0][0];
    for (int i = 0, j = 0; i < row; i++, j++)
    {
        if (min > arr[i][j])
            min = arr[i][j];

        if (max < arr[i][j])
            max = arr[i][j];
    }
    cout << "Minimum is: " << min << ", and the maximum is: " << max << ".\n";
}

void matrix_min_max(double(&arr)[row][col])
{
    double min = arr[0][0];
    double max = arr[0][0];
    for (int i = 0, j = 0; i < row; i++, j++)
    {
        if (min > arr[i][j])
            min = arr[i][j];

        if (max < arr[i][j])
            max = arr[i][j];
    }
    cout << "Minimum is: " << min << ", and the maximum is: " << max << ".\n";
}

void sort_matrix(int(&arr)[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = row - 1; k > j; k--)
                if (arr[i][k - 1] > arr[i][k])
                {
                    int tmp = arr[i][k];
                    arr[i][k] = arr[i][k - 1];
                    arr[i][k - 1] = tmp;
                }
        }
    }
}

void sort_matrix(double(&arr)[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = row - 1; k > j; k--)
                if (arr[i][k - 1] > arr[i][k])
                {
                    double tmp = arr[i][k];
                    arr[i][k] = arr[i][k - 1];
                    arr[i][k - 1] = tmp;
                }
        }
    }
}


// task 2

int greatest_common_divisor(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    if (a > b)
    {
        return greatest_common_divisor(b, a % b);
    }
    else
    {
        return greatest_common_divisor(a, b % a);
    }
}


//task 3

void computer_guess(int* arr, int len)
{
    int temp;    

    for (int i = 0; i < len; i++)
    {
        temp = 1 + rand() % 9;

        while (temp == arr[0] || temp == arr[1] || temp == arr[2] || temp == arr[3])
        {
            temp = 1 + rand() % 9;
        }
        arr[i] = temp;
        
    }
}

void user_guess_number(int* arr, int len)
{
    int user_number;
    cout << "Please enter 4 digit number (numbers can not be the same)->";
    cin >> user_number;
    for(int i = len-1; i >= 0; i--)
    {
        arr[i] = user_number % 10;
        user_number = user_number / 10;
    }
}

void game(int* comp_arr, int* user_arr, int len)
{
    int bulls = 0;
    int number_of_tries = 0;
    while (bulls != 4)
    {
        int cows = 0;
        bulls = 0;
        user_guess_number(user_arr, len);
        for (int i = 0; i < len; i++)
        {
            if (comp_arr[i] == user_arr[i])
                bulls++;
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (comp_arr[i] == user_arr[j] && i != j)
                    cows++;
            }
        }
        for (int i = 0; i < len; i++)
        {
            cout << user_arr[i];
        }
        cout << " -> ";
        cout << "cows = " << cows << " bulls = " << bulls << "." << endl;
        number_of_tries++;
    }
    cout << "You win! Number of tries is " << number_of_tries << "." << endl;
}
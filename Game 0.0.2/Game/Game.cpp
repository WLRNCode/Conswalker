#include <iostream>
#include <iomanip>
//setw(4)
#include <random>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
//..
using namespace std;
int x;
int y;
int xy = -1;
int yy = -1;
const int w = 20;
const int h = 20;

void setcur(long x, long y)//установка курсора на позицию  x y 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void seen(char arr[h][w])
{
    setcur(0, 0);
    //system("cls");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {

            cout << arr[i][j];

        }
        cout << endl;
    }

}

void coord(char arr[h][w])
{
    int a = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == '@')
            {
                x = j;
                y = i;
            }

        }
    }
    cout << "X[" << x << "] " << "Y[" << y << "] " << xy << " " << yy << " " << endl;
    
}
void coordy(char arr[h][w])
{

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == '*')
            {
                xy = j;
                yy = i;
            }

        }
    }

}
void enter(char arr[h][w])
{
    char s = _getch();
    int a = 0;
    if (s == 's')
    {
        if (arr[y + 1][x] == '.')
        {
            swap(arr[y][x], arr[y + 1][x]);
            coordy(arr);
            arr[yy][xy] = '.';
            xy = -1;
            yy = -1;
            seen(arr);
            coord(arr);
        }
        if (arr[y + 1][x] == '#')
        {

        }
        if (arr[y + 1][x] == '%')
        {

        }

    }
    if (s == 'w')
    {
        if (arr[y - 1][x] == '.')
        {
            swap(arr[y][x], arr[y - 1][x]);
            coordy(arr);
            arr[yy][xy] = '.';
            xy = -1;
            yy = -1;
            seen(arr);
            coord(arr);
        }
        if (arr[y + 1][x] == '#')
        {

        }
        if (arr[y + 1][x] == '%')
        {

        }

    }
    if (s == 'd')
    {
        if (arr[y][x + 1] == '.')
        {
            swap(arr[y][x], arr[y][x + 1]);
            coordy(arr);
            arr[yy][xy] = '.';
            xy = -1;
            yy = -1;
            seen(arr);
            coord(arr);
        }
        if (arr[y + 1][x] == '#')
        {

        }
        if (arr[y + 1][x] == '%')
        {

        }

    }
    if (s == 'a')
    {
        if (arr[y][x - 1] == '.')
        {
            swap(arr[y][x], arr[y][x - 1]);
            coordy(arr);
            arr[yy][xy] = '.';
            xy = -1;
            yy = -1;
            seen(arr);
            coord(arr);
        }
        if (arr[y + 1][x] == '#')
        {

        }
        if (arr[y + 1][x] == '%')
        {

        }

    }
    if (s == '8')
    {
        if (arr[y - 1][x] == '.')
        {
            coordy(arr);
            arr[yy][xy] = '.';
            arr[y - 1][x] = '*';
            coordy(arr);
            seen(arr);
            coord(arr);
        }
        
        if (arr[y - 1][x] == '%')
        {
            arr[y - 1][x] = '.';
            seen(arr);
            coord(arr);
        }

    }
    if (s == '2')
    {
        if (arr[y + 1][x] == '.')
        {
            coordy(arr);
            arr[yy][xy] = '.';
            arr[y + 1][x] = '*';
            coordy(arr);
            seen(arr);
            coord(arr);
        }
        
        if (arr[y + 1][x] == '%')
        {
            arr[y + 1][x] = '.';
            seen(arr);
            coord(arr);
        }
    }
    if (s == '4')
    {
        if (arr[y][x - 1] == '.')
        {
            coordy(arr);
            arr[yy][xy] = '.';
            arr[y][x - 1] = '*';
            coordy(arr);
            seen(arr);
            coord(arr);
        }
        
        if (arr[y][x - 1] == '%')
        {
            arr[y][x - 1] = '.';
            seen(arr);
            coord(arr);
        }
    }
    if (s == '6')
    {
        if (arr[y][x + 1] == '.')
        {
            coordy(arr);
            arr[yy][xy] = '.';
            arr[y][x + 1] = '*';
            coordy(arr);
            seen(arr);
            coord(arr);
        }
        
        if (arr[y][x + 1] == '%')
        {
            arr[y][x + 1] = '.';
            seen(arr);
            coord(arr);
        }
    }
    if (s == '1')
    {
        if (xy != -1 && yy != -1)
        {
            arr[yy][xy] = '#';
            xy = -1;
            yy = -1;
            seen(arr);
            coord(arr);
        }
            
    }
    if (s == '3')
    {
        if (xy != -1 && yy != -1)
        {
            arr[yy][xy] = '%';
            xy = -1;
            yy = -1;
            seen(arr);
            coord(arr);
        }

    }




}

int main()
{
    setlocale(LC_ALL, "RU");
    char map[h][w]; 
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            map[i][j] = '#';
        }
    }
    for (int i = 1; i < h-1; i++)
    {
        for (int j = 1; j < w-1; j++)
        {
            map[i][j] = '.';
        }
    }



    int a = 0, b, c;
    // Инициализируем генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());

    // Определяем диапазон случайных чисел
    int min = 1;
    int max = h-2;

    // Создаем распределение случайных чисел
    uniform_int_distribution<> dis(min, max);

    // Генерируем случайное число
    int randomNum = dis(gen);
    int randomNum1 = dis(gen);
    map[h - randomNum][h - randomNum1] = '@';
    seen(map);
    coord(map);
    
    while (true)
    {

        enter(map);

    }
    //ch = _getch();
        //if (ch == 224) //Проверка нажатия функциональной клавиши
        //{
        //    ch = _getch();
        //    switch (ch)
        //    {
        //    case 75: printf("left\n"); break;
        //    case 77: printf("right\n"); break;
        //    case 72: printf("up\n"); break;
        //    case 80: printf("down\n"); break;
        //    default: printf("unknown\n");
        //    }

        //}

}

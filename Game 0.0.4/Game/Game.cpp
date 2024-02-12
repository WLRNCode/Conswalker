#include <iostream>
#include <iomanip>
//setw(4)
#include <random>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string>

#define RED "\033[31;1m" 
#define GREEN "\033[32m" 
#define WHITE "\033[37m" 
#define YELLOW "\033[33m" 
#define BLUE "\033[34;1m" 
#define CYAN "\033[36;1m" 
#define DEFAULT_COLOR "\033[m" 
#define PINK "\033[35;1m" 
#define BACKGROUND_GREY "\033[48;5;235m" 
#define DEFAULT_BACKGROUND_COLOR "\033[40m" 
#define RGBC "\033[38;2;0;0;0m"
#define CLEAR_LINE() (cout<<"\033[2K") 
#define CLEAR_TO_END() (cout<<"\033[0J") 
#define TO_COLUMN(num) (cout<<"\033["+to_string(num)+"G") 
#define TO_POSITION(row, column) (cout<<"\033[" + to_string(row) + ";" + to_string(column) +"H") 
#define CLEAR_LINE_TO_END() (cout<<"\033[0K") 
#define UP_LINE() (cout << "\033[1A") 
#define UP_LINES(x) (cout << "\033[" + to_string(x) + "F") 
#define DOWN_LINES(x) (cout << "\033[" + to_string(x) + "E") 
#define CURSOR_FORWARD (cout << "\033[1C") 
#define CURSOR_BACK (cout << "\033[1D")

//..
using namespace std;
int x;
int y;
const int w = 60; //71
const int h = 30;
int blocks = 2;
int blocks1 = 20;
int hand = 2;
char handcolor = 'r';

void setcur(short x, short y)//установка курсора на позицию  x y 
{
    /*TO_POSITION(0, 0);
    CLEAR_TO_END();*/
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void seen(char arr[h][w], char color[h][w])
{
    setcur(0, 0);
    //system("cls");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == '%')
            {
                if (color[i][j] == 'r')
                {
                    cout << RED << arr[i][j] << WHITE;
                }
                if (color[i][j] == '0')
                {
                    cout << WHITE << arr[i][j] << WHITE;
                }
                
            }  
            else if (arr[i][j] == '.')
            {
                cout << WHITE << arr[i][j];
            }
            else
            {
                cout << arr[i][j];
            }

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
    cout << WHITE << "X[" << x << "] " << "Y[" << y << "] " << " " << endl;
    cout << WHITE << "#[" << blocks1 << "] " << "%[" << blocks << "] ";
    if (hand == 0)
    {
        cout << WHITE << "In hand [ ]";
    }
    if (hand == 1)
    {
        cout << WHITE << "In hand [#]";
    }
    if (hand == 2)
    {
        cout << WHITE << "In hand [%]";
    }
    
}

void enter(char arr[h][w], char color[h][w])
{
    char s = _getch();
    int a = 0;
    switch (s)
    {
        case 72: 
            if (arr[y - 1][x] == '.')
            {
                if (hand == 1 && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y - 1][x] = '#';
                    seen(arr, color); 
                    coord(arr);
                }
                if (hand == 2 && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y - 1][x] = '%';
                    color[y - 1][x] = handcolor; 
                    seen(arr, color);
                    coord(arr);
                    

                }
            }
            if (arr[y - 1][x] == '%' && hand == 0)
            {
                blocks = blocks + 1;
                arr[y - 1][x] = '.';
                color[y - 1][x] = '0';
                seen(arr, color);
                coord(arr);
            }
            break;
        case 80:
            if (arr[y + 1][x] == '.')
            {
                if (hand == 1 && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y + 1][x] = '#';
                    seen(arr, color);
                    coord(arr);
                }
                if (hand == 2 && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y + 1][x] = '%';
                    color[y + 1][x] = handcolor;
                    seen(arr, color);
                    coord(arr);
                    
                }
            }
            if (arr[y + 1][x] == '%' && hand == 0)
            {
                blocks = blocks + 1;
                arr[y + 1][x] = '.';
                color[y + 1][x] = '0';
                seen(arr, color);
                coord(arr);
            }
            break;
        case 75:
            if (arr[y][x - 1] == '.')
            {
                if (hand == 1 && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y][x - 1] = '#';
                    seen(arr, color);
                    coord(arr);
                }
                if (hand == 2 && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y][x - 1] = '%';
                    color[y][x - 1] = handcolor;
                    seen(arr, color);
                    coord(arr);
                    
                }
            }
            if (arr[y][x - 1] == '%' && hand == 0)
            {
                blocks = blocks + 1; 
                arr[y][x - 1] = '.'; 
                color[y][x - 1] = '0';
                seen(arr, color);
                coord(arr);
            }
            break;
        case 77:
            if (arr[y][x + 1] == '.')
            {
                if (hand == 1 && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y][x + 1] = '#';
                    seen(arr, color);
                    coord(arr);
                }
                if (hand == 2 && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y][x + 1] = '%';
                    color[y][x + 1] = handcolor;
                    seen(arr, color);
                    coord(arr);
                    
                }
            }
            if (arr[y][x + 1] == '%' && hand == 0)
            {
                blocks = blocks + 1;
                arr[y][x + 1] = '.';
                color[y][x + 1] = '0';
                seen(arr, color);
                coord(arr);
            }
            break;
        case 'w':
            if (arr[y - 1][x] == '.')
            {
                swap(arr[y][x], arr[y - 1][x]);
                seen(arr, color);
                coord(arr);
            }
            if (arr[y + 1][x] == '#')
            {
                
            }
            if (arr[y + 1][x] == '%')
            {

            }
            break;
        case 's':
            if (arr[y + 1][x] == '.')
            {
                swap(arr[y][x], arr[y + 1][x]);
                
                seen(arr, color);
                coord(arr);
            }
            if (arr[y + 1][x] == '#')
            {

            }
            if (arr[y + 1][x] == '%')
            {

            }
            break;
        case 'a':
            if (arr[y][x - 1] == '.')
            {
                swap(arr[y][x], arr[y][x - 1]);
                
                seen(arr, color);
                coord(arr);
            }
            if (arr[y + 1][x] == '#')
            {

            }
            if (arr[y + 1][x] == '%')
            {

            }
            break;
        case 'd':
            if (arr[y][x + 1] == '.')
            {
                swap(arr[y][x], arr[y][x + 1]);
                
                seen(arr,color);
                coord(arr);
            }
            if (arr[y + 1][x] == '#')
            {

            }
            if (arr[y + 1][x] == '%')
            {

            }
            break;      
        case '2':
            hand = 2;
            seen(arr, color);
            coord(arr);
            break;
        case '9':
            handcolor = 'r';
            seen(arr, color);
            coord(arr);
            break;
        case '8':
            handcolor = '0';
            seen(arr, color);
            coord(arr);
            break;
        case '1':
            hand = 1;
            seen(arr, color);
            coord(arr);
            break;
        case '0':
            hand = 0;
            seen(arr, color);
            coord(arr);
            break;
        
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = false;
    cursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    char color[h][w];
    char map[h][w]; 
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            map[i][j] = '#';
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            color[i][j] = '0';
        }
    }
    for (int i = 1; i < h-1; i++)
    {
        for (int j = 1; j < w-1; j++)
        {
            map[i][j] = '.';
        }
    }



    int a = 0, b=0, c=0;
    // Инициализируем генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());

    // Определяем диапазон случайных чисел
    int min = 1;
    int max = 20;

    // Создаем распределение случайных чисел
    uniform_int_distribution<> dis(min, max);

    // Генерируем случайное число
    int randomNum = dis(gen);
    int randomNum1 = dis(gen);
    
    map[h - randomNum][h - randomNum1] = '@';
    seen(map,color); 
    coord(map);
    while (true)
    {
        Sleep(10);
        enter(map,color); 
        
    }

}

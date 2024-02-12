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
#define RGBC "\033[38;2;255;255;0m"
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
const int w = 30; //71
const int h = 30;
int blocks = 20;
int blocks1 = 20;
int blocksbomb = 20;
int bombx = 0;
int bomby = 0;
char hand = ' '; 
int radiusbomb = 5;
string handcolor = "WHITE";
void setcur(short x, short y)//установка курсора на позицию  x y 
{
    /*TO_POSITION(0, 0);
    CLEAR_TO_END();*/
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void seen(char arr[h][w], string color[h][w])
{
    setcur(0, 0);
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == '#')
            {
                cout << RED << setw(2) << arr[i][j] << WHITE;
            }
            else if (arr[i][j] == '%')
            {
                if (color[i][j] == "RED")
                {
                    cout << RED << setw(2) << arr[i][j] << WHITE;
                }
                if (color[i][j] == "WHITE")
                {
                    cout << WHITE << setw(2) << arr[i][j] << WHITE;
                }
                
            }
            else if (arr[i][j] == '.')
            {
                cout << WHITE << setw(2) << arr[i][j] << WHITE;
            }
            else if (arr[i][j] == '*')
            {
                cout << RGBC << setw(2) << arr[i][j] << WHITE;
            }
            else
            {
                cout << setw(2) << arr[i][j];
            }

        }
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
        if (i == 0)
        {
            cout << "  " << WHITE << "X[" << x << "] " << "Y[" << y << "] " << " ";
        }
        if (i == 1)
        {
            cout << "  " << WHITE << "#[" << blocks1 << "] " << "%[" << blocks << "] " << "*[" << blocksbomb << "] ";
        }
        if (i == 2)
        {
            
            cout << "  " << WHITE << "In hand [" << hand <<"]";
            
        }
        if (i == 3)
        {
            
            cout << "  " << WHITE << "Color block [" << handcolor <<"]  ";
            
        }
        if (i != h - 1)
        {
            cout << endl;
        }
        
    }

}
void bomb(char arr[h][w], string color[h][w])
{
    arr[bomby][bombx] = '*';
    seen(arr, color);
    Sleep(500);
    for (int r = 0; r < radiusbomb; r++)
    {
        for (int i = 0; i < 3 + (r * 2); i++)
        {
            for (int j = 0; j < 3 + (r * 2); j++)
            {
                if (arr[bomby + 1 - i + r][bombx - j + 1 + r] == '%')
                {
                    arr[bomby + 1 - i + r][bombx - j + 1 + r] = '*';
                    blocks = blocks + 1;
                }
                if (arr[bomby + 1 - i + r][bombx - j + 1 + r] == '#')
                {
                    
                    
                }
                if (arr[bomby + 1 - i + r][bombx - j + 1 + r] == '.')
                {
                    arr[bomby + 1 - i + r][bombx - j + 1 + r] = '*';
                }
            }
        }
        seen(arr, color);
    }
    for (int i = 0; i < 3 + (radiusbomb * 2) - 1; i++)
    {
        for (int j = 0; j < 3 + (radiusbomb * 2) - 1; j++)
        {
            if (arr[bomby + 1 - i + radiusbomb][bombx - j + 1 + radiusbomb] == '*')
            {
                arr[bomby + 1 - i + radiusbomb][bombx - j + 1 + radiusbomb] = '.';
            }
            


        }

    }
    arr[y][x] = '@';
    seen(arr, color);
}
void enter(char arr[h][w], string color[h][w])
{
    
    char s = _getch();
    Sleep(17);
    
    switch (s)
    {
    case 'w':
        if (arr[y - 1][x] == '.')
        {
            swap(arr[y][x], arr[y - 1][x]);

            seen(arr, color);
            break;

        }
        if (arr[y + 1][x] == '#')
        {
            break;
        }
        if (arr[y + 1][x] == '%')
        {
            break;
        }
        
        break;
    case 's':
        if (arr[y + 1][x] == '.')
        {
            swap(arr[y][x], arr[y + 1][x]);

            seen(arr, color);
            break;

        }
        if (arr[y + 1][x] == '#')
        {
            break;
        }
        if (arr[y + 1][x] == '%')
        {
            break;
        }
        break;
    case 'a':
        if (arr[y][x - 1] == '.')
        {
            swap(arr[y][x], arr[y][x - 1]);

            seen(arr, color);
            break;

        }
        if (arr[y + 1][x] == '#')
        {
            break;
        }
        if (arr[y + 1][x] == '%')
        {
            break;
        }
        break;
    case 'd':
        if (arr[y][x + 1] == '.')
        {
            swap(arr[y][x], arr[y][x + 1]);

            seen(arr, color);
            break;

        }
        if (arr[y + 1][x] == '#')
        {
            break;
        }
        if (arr[y + 1][x] == '%')
        {
            break;
        }
        break;
        case 72: 
            if (arr[y - 1][x] == '.')
            {
                if (hand == '#' && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y - 1][x] = '#';
                    seen(arr, color);
                    break;
                }
                if (hand == '%' && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y - 1][x] = '%';
                    color[y - 1][x] = handcolor;
                    seen(arr, color);
                    break;
                }
                if (hand == '*' && blocksbomb > 0)
                {
                    blocksbomb = blocksbomb - 1;
                    bombx = x;
                    bomby = y - 1;
                    bomb(arr, color);
                    break;

                }
                if (arr[y - 1][x] == '%' && hand == ' ')
                {
                    blocks = blocks + 1;
                    arr[y - 1][x] = '.';
                    color[y - 1][x] = "WHITE";
                    seen(arr, color);
                    break;

                }
            }
                break;
        case 80:
            if (arr[y + 1][x] == '.')
            {
                if (hand == '#' && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y + 1][x] = '#';
                    seen(arr, color);
                    break;

                }
                if (hand == '%' && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y + 1][x] = '%';
                    color[y + 1][x] = handcolor;
                    seen(arr, color);
                    break;


                }
                if (hand == '*' && blocksbomb > 0)
                {
                    blocksbomb = blocksbomb - 1;
                    bombx = x;
                    bomby = y + 1;
                    bomb(arr, color);
                    break;
                }
            }
            if (arr[y + 1][x] == '%' && hand == ' ')
            {
                blocks = blocks + 1;
                arr[y + 1][x] = '.';
                color[y + 1][x] = "WHITE";
                seen(arr, color);
                break;

            }
            break;
        case 75:
            if (arr[y][x - 1] == '.')
            {
                if (hand == '#' && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y][x - 1] = '#';
                    seen(arr, color);
                    break;

                }
                if (hand == '%' && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y][x - 1] = '%';
                    color[y][x - 1] = handcolor;
                    seen(arr, color);
                    break;


                }
                if (hand == '*' && blocksbomb > 0)
                {
                    blocksbomb = blocksbomb - 1;
                    bombx = x - 1;
                    bomby = y;
                    bomb(arr, color);
                    break;
                }
                if (arr[y][x - 1] == '%' && hand == ' ')
                {
                    blocks = blocks + 1;
                    arr[y][x - 1] = '.';
                    color[y][x - 1] = "WHITE";
                    seen(arr, color);
                    break;

                }
                break;
        case 77:
            if (arr[y][x + 1] == '.')
            {
                if (hand == '#' && blocks1 > 0)
                {
                    blocks1 = blocks1 - 1;
                    arr[y][x + 1] = '#';
                    seen(arr, color);
                    break;
                }
                if (hand == '%' && blocks > 0)
                {
                    blocks = blocks - 1;
                    arr[y][x + 1] = '%';
                    color[y][x + 1] = handcolor;
                    seen(arr, color);
                    break;


                }
                if (hand == '*' && blocksbomb > 0)
                {
                    blocksbomb = blocksbomb - 1;
                    bombx = x + 1;
                    bomby = y;
                    bomb(arr, color);
                    break;
                }
                if (arr[y][x + 1] == '%' && hand == ' ')
                {
                    blocks = blocks + 1;
                    arr[y][x + 1] = '.';
                    color[y][x + 1] = "WHITE";
                    seen(arr, color);
                    break;

                }
            }
            break;
        case '2':
            hand = '%';
            seen(arr, color);

            break;
        case '3':
            hand = '*';
            seen(arr, color);

            break;
        case '9':
            handcolor = "RED";
            seen(arr, color);

            break;
        case '8':
            handcolor = "WHITE";
            seen(arr, color);

            break;
        case '1':
            hand = '#';
            seen(arr, color);

            break;
        case '0':
            hand = ' ';
            seen(arr, color);

            break;
            }
    }

}

int main()
{
    setlocale(LC_ALL, "RU");
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = false;
    cursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    string color[h][w];
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
            color[i][j] = "WHITE";
        }
    }
    for (int i = 1; i < h-1; i++)
    {
        for (int j = 1; j < w-1; j++)
        {
            map[i][j] = '.';
        }
    }



    
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
    
    while (true)
    {
        
        enter(map,color);
        
        
    }

}

#include <stdio.h>
#include <string.h>
void check_weights(char board[][9])
{
    int len = strlen(board[0]);
    int whites = 0;
    int count_w = 0;
    int count_b = 0;
    int blacks = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (board[i][j] == 'Q')
            {
                whites += 9;
                count_w++;
            }
            else if (board[i][j] == 'R')
            {
                whites += 5;
                count_w++;
            }
            else if (board[i][j] == 'N' || board[i][j] == 'B')
            {
                whites += 3;
                count_w++;
            }
            else if (board[i][j] == 'P')
            {
                whites += 1;
                count_w++;
            }

            else if (board[i][j] == 'q')
            {
                blacks += 9;
                count_b++;
            }
            else if (board[i][j] == 'r')
            {
                blacks += 5;
                count_b++;
            }
            else if (board[i][j] == 'n' || board[i][j] == 'b')
            {
                blacks += 3;
                count_b++;
            }
            else if (board[i][j] == 'p')
            {
                blacks += 1;
                count_b++;
            }
        }
    }
    if (blacks > whites)
    {
        printf("Black");
    }
    else if (blacks == whites)
        printf("Draw");
    else
        printf("White");
    return;
}
int main()
{
    char board[8][9];

    for (int i = 0; i < 8; i++)
    {
        scanf("%s", board[i]);
    }
    int len = strlen(board[0]);

    check_weights(board);
    return 0;
}
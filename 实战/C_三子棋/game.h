#define Row 3
#define Col 3

void InitBoard(char board[Row][Col], int row, int col);
void DisplayBoard(char board[Row][Col], int row, int col);
void PlayerMove(char board[Row][Col], int row, int col);
void ComputerMove(char board[Row][Col], int row, int col);
char IsWin(char board[Row][Col], int row, int col);
int IsFull(char board[Row][Col], int row, int col);
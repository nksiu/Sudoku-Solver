#include <stdio.h>

void printSudoku(void);
int solveSudoku(int, int);
int checkRow(int, int);
int checkColumn(int, int);
int checkBox(int, int, int);

int sudoku1[9][9] = {{0, 0, 0, 0, 0, 0, 0, 9, 0},
					{1, 9, 0, 4, 7, 0, 6, 0, 8},
					{0, 5, 2, 8, 1, 9, 4, 0, 7},
					{2, 0, 0, 0, 4, 8, 0, 0, 0},
					{0, 0, 9, 0, 0, 0, 5, 0, 0},
					{0, 0, 0, 7, 5, 0, 0, 0 ,9},
					{9, 0, 7, 3, 6, 4, 1, 8, 0},
					{5, 0, 6, 0, 8, 1, 0, 7, 4},
					{0, 8, 0, 0, 0, 0, 0, 0, 0}};

int main(){
	int x = 0;
	int y = 0;
	
	solveSudoku(x, y);
	printSudoku();

	return 0;

}

void printSudoku(){
	printf("+-----+-----+-----+\n");
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			printf("|%d", sudoku1[i][j]);
			if (j == 8){
				printf("|");
			}
			if (i == 2 && j == 8){
				printf("\n+-----+-----+-----+");
			}

			if (i == 5 && j == 8){
				printf("\n+-----+-----+-----+");
			}
		}
		printf("\n");
	}
	printf("+-----+-----+-----+\n");
}

int ColumnContains(int x, int num){
	for (int j = 0; j < 9; j++){
		if (sudoku1[x][j] == num){
			return 1;
		}
	}
	return 0;
}

int RowContains(int y, int num){
	for (int i = 0; i < 9; i++){
		if (sudoku1[i][y] == num){
			return 1;
		}
	}
	return 0;
}

int BoxContains(int x, int y, int num){
	if (x < 3){
		x = 0;
	} else if(x < 6){
		x = 3;
	} else{
		x = 6;
	}

	if (y < 3){
		y = 0;
	} else if(y < 6){
		y = 3;
	} else{
		y = 6;
	}

	for (int i = x; i < x+3; i++){
		for (int j = y; j < y+3; j++){
			if (sudoku1[i][j] == num){
				return 1;
			}
		}
	}
	return 0;
}


int solveSudoku(int x, int y){
	int val = 1;
	int tempx = 0;
	int tempy = 0;

	if (sudoku1[x][y] != 0){
		if (x < 8){
			x++;
		}else{
			x = 0;
			y++;
		}
		if (solveSudoku(x, y)){
			return 1;
		} else{
			return 0;
		}
	}

	if (sudoku1[x][y] == 0){
		while (val < 10){
			if (!RowContains(y, val) && !ColumnContains(x, val) && !(BoxContains(x, y, val))){
				sudoku1[x][y] = val;
				
				if (x == 8 && y == 8){
					return 1;
				}

				if (x < 8){
					tempx = x + 1;
				} else{
					if (y < 8){
						tempx = 0;
						tempy = y + 1;
					}
				}

				if (solveSudoku(tempx, tempy)){
					return 1;
				}
			}
			val++;
		}
	}
	sudoku1[x][y] = 0;
	return 0;
}
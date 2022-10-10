/*
목적
1. 틱택토의 모든 경우의 수를 탐색
2. 최선의 수를 뒀을 때 항상 무승부가 나오는지 탐구

유형 : 심심풀이
마지막 업데이트 : 2022-10-10
*/
#include <iostream>
#define NONE 0
#define O 1
#define X 2
#define SIZE 3

int is_end(int board[][3]){
	int row, col, diag = board[0][0], re_diag = board[0][SIZE-1];
	for(int i=0; i<SIZE; i++){
		row = board[i][0], col = board[0][i];
		for(int j=0; j<SIZE; j++){
			if(board[i][j] == NONE){
				return -1;
			}
			row &= board[i][j];
			col &= board[j][i];
		}
		
		if(row == board[i][0]){
			return row;
		}
		else if(col == board[0][i]){
			return col;
		}
	}
	
	
	for(int i=0; i<SIZE; i++){
		diag &= board[i][i];
		re_diag &= board[i][SIZE-1-i];
	}
	if(diag == board[0][0]){
		return diag;
	}
	else if(diag == board[0][SIZE-1]){
		return re_diag;
	}
	
	return NONE;
}



int is_possible(int board[][3], int x, int y){
	return board[x][y] == NONE ? 1 : 0;
}

void count_all_case(int board[][3], int mark, int *count){
	int judge = is_end(board);
	if(judge != -1){
		count[judge]++;
		return;
	}
	
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(is_possible(board, i, j)){
				board[i][j] = mark;
				count_all_case(board, mark == O ? X : O, count);
				board[i][j] = NONE;
			}
			
		}
	}
}

int main(int argc, char* argv[]) {
	int board[SIZE][SIZE]={}, count[SIZE]={};
	
	count_all_case(board, O, count);
	std::cout << "draw : " << count[NONE] << '\n';
	std::cout << "O win : " << count[O] << '\n';
	std::cout << "X win : " << count[X] << '\n';
	
	
}
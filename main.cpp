#include <iostream>
using namespace std;

int min(int, int);

int main() {
	const bool T = true, F = false;
	const int N = 9;
	//defining a 4x4 chess board ('T' represents a queen and 'F', no queen)
	bool pos[N][N] = {
		{F,F,F,F,T,F,F,F,F},
		{F,F,F,F,F,F,T,F,F},
		{F,F,F,F,F,F,F,F,T},
		{F,F,F,T,F,F,F,F,F},
		{F,T,F,F,F,F,F,F,F},
		{F,F,F,F,F,F,F,T,F},
		{F,F,F,F,F,T,F,F,F},
		{F,F,T,F,F,F,F,F,F},
		{T,F,F,F,F,F,F,F,F}
	};

	//There are only two correct solution for a 4x4 chess board. These are: 
	//correct solution-1
	const bool pos_[4][4] = {
		{F,T,F,F},
		{F,F,F,T},
		{T,F,F,F},
		{F,F,T,F}
	};
	//correct solution-2
	const bool pos__[4][4] = {
		{F,F,T,F},
		{T,F,F,F},
		{F,F,F,T},
		{F,T,F,F}
	};


	//looping to produce 4x4x4x4 different possible arrangements
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

		}
	}

    //explanations for all conditions are given in README

	//........................checking condition 1: C1...............................
	// C1: Condition that every row contains at least one queen. (Note that it won't flag any error if there are two or more of them).
	bool temp_1 = F;      //something OR F is always something
	bool result_1 = T;    //something AND T is always something
	for (int i = 0; i < N; i++) {
		temp_1 = F;  //make sure temp is 'F' before it enters the inner loop
		for (int j = 0; j < N; j++) {
			temp_1 = temp_1 || pos[i][j];
		}
		result_1 = result_1 && temp_1;
	}

	cout << "Whether condition 1 is satisfied (false: 0, true: 1): " << result_1 << endl;







	//........................checking condition 2: C2...............................
	// C2: Condition for at most one queen in each row. (asserts true even if zero queen in a row)
	bool temp_2, temp_3=T, result_2=T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			temp_2 = T;
			for (int k = j+1; k < N; k++) {
				temp_2 = temp_2 && (!pos[i][j] || !pos[i][k]);
			}
			temp_3 = temp_3 && temp_2;
		}
		result_2 = result_2 && temp_3;
	}

	cout << "Whether condition 2 is satisfied (false: 0, true: 1): " << result_2 << endl;






	//........................checking condition 3: C3...............................
	// C3: Condition for at most one queen in each column. (asserts true even if zero queen in a column)
	bool temp_4, temp_5 = T, result_3 = T;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			temp_4 = T;
			for (int k = i + 1; k < N; k++) {
				temp_4 = temp_4 && (!pos[i][j] || !pos[k][j]);
			}
			temp_5 = temp_5 && temp_4;
		}
		result_3 = result_3 && temp_5;
	}
	cout << "Whether condition 3 is satisfied (false: 0, true: 1): " << result_3 << endl;








	//........................checking condition 4: C4...............................
	// C4: Asserting no (left-inclined) diagonal contains two queens.
	bool temp_6=T, temp_7=T, result_4 = T;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp_6 = T;
			for (int k = 1; k < min(N - i, N - j); k++) {
				temp_6 = temp_6 && (!pos[i][j] || !pos[i + k][j + k]);
			}
			temp_7 = temp_7 && temp_6;
		}
		result_4 = result_4 && temp_7;
	}
	cout << "Whether condition 4 is satisfied (false: 0, true: 1): " << result_4 << endl;






	//........................checking (last) condition 5: C5...............................
	// C5: Asserting no (right-inclined) diagonal contains two queens.
	bool temp_8 = T, temp_9 = T, result_5 = T;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp_8 = T;
			for (int k = 1; k < min(i - 1, N - j); k++) {
				temp_8 = temp_8 && (!pos[i][j] || !pos[i - k][k + j]);
			}
			temp_9 = temp_9 && temp_8;
		}
		result_5 = result_5 && temp_9;
	}
	cout << "Whether condition 5 is satisfied (false: 0, true: 1): " << result_5 << endl;

	bool f_result = result_1 && result_2 && result_3 && result_4 && result_5;
	cout << "\nHence, the given arrangement of queens on the " << N << "x" << N << " chess board is ";
	cout << (f_result == true ? "POSSIBLE." : "NOT possible.") << endl;
	return 0;
}

int min(int x, int y) {
	return x < y ? x : y;
}
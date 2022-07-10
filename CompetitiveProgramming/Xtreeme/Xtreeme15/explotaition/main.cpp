#include <iostream>
using namespace std;

long long mat[1000+5][1000+5];
long long dp[1000+5][1000+5];

long long max_sum = 0;

void NumMatrix(long long R, long long C) {
    for (long long r = 0; r < R; r++) {
        for (long long c = 0; c < C; c++) {
            dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + mat[r][c] - dp[r][c];
        }
    }
}

long long sumRegion(long long row1, long long col1, long long row2, long long col2) {
    return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
}

long long np_sum(long long row1, long long row2, long long col1, long long col2){
    return sumRegion(row1, col1, row2-1, col2-1);
}


long long check_if_second_mat_fits(long long row1, long long row2, long long col1, long long col2, long long R, long long C, long long Y, long long X){
    long long sum = 0;
    for(long long i = 0; i< R-Y; i++){
        for(long long j = 0; j < C-X; j++){
            long long curr_row1 = i;
            long long curr_row2 = i+Y;
            long long curr_col1 = j;
            long long curr_col2 = j+X;
            // if overlaps it's not good
            bool overlaps = false;
            if((row1 <= curr_row1 && curr_row1 <= row2)){
                if((col1 <= curr_col1 && curr_col1 <= col2)){
                    overlaps = true;
                }
            }
            if(!overlaps){
                sum = max(np_sum(curr_row1, curr_row2, curr_col1, curr_col2), sum);
            }
        }
    }

    for(long long i = 0; i< R-X; i++){
        for(long long j = 0; j < C-Y; j++){
            long long curr_row1 = i;
            long long curr_row2 = i+X;
            long long curr_col1 = j;
            long long curr_col2 = j+Y;
            // if overlaps it's not good
            bool overlaps = false;
            if((row1 <= curr_row1 && curr_row1 <= row2)){
                if((col1 <= curr_col1 && curr_col1 <= col2)){
                    overlaps = true;
                }
            }
            if(!overlaps){
                sum = max(np_sum(curr_row1, curr_row2, curr_col1, curr_col2), sum);
            }
        }
    }

    return sum;
}

int main() {
    long long R,C,X,Y,aux;
    cin >> R;
    cin >> C;
    cin >> X;
    cin >> Y;


    for (long long i = 0; i < R; i++) {
        for(long long j = 0; j < C; j++){
            cin >> aux;
            mat[i][j] = aux;
        }
    }

    NumMatrix(R,C);


    for(long long i = 0; i< R-Y; i++){
        for(long long j = 0; j < C-X; j++){
            // got the starting indexes
            long long s = np_sum(i,i+Y, j, j+X);
            s += check_if_second_mat_fits(i, i+Y, j, j+X, R,C ,Y ,X); // if cant -> sums 0
            max_sum = max(max_sum, s);
        }
    }

    for(long long i = 0; i< R-X; i++){
        for(long long j = 0; j < C-Y; j++){
            // got the starting indexes
            long long s = np_sum(i,i+X, j, j+Y);
            s += check_if_second_mat_fits(i, i+X, j, j+Y, R,C ,X ,Y); // if cant -> sums 0
            max_sum = max(max_sum, s);
        }
    }

    cout << max_sum ;

    return 0;
}

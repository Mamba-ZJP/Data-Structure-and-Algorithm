#include<iostream>
#include<vector>
using namespace std;

vector<vector<double>> matrix; 
int n;

int main(void){
    cin >> n;
    matrix.resize(n,vector<double>(2 * n,0.0));
    for(int r = 0;r < n;++r){
        for(int c = 0;c < n;++c) cin >> matrix[r][c];
        matrix[r][n + r] = 1.0;
    }
    
    for(int r = 0;r < n;++r){
        double cur = matrix[r][r];
        //单位化
        for(int c = 0;c < 2 * n;++c) matrix[r][c] /= cur;

        for(int aim_r = 0;aim_r < n;++aim_r){
            if(aim_r == r || !matrix[aim_r][r]) continue;

            double coef = matrix[aim_r][r] * (-1.0);
            for(int aim_c = 0;aim_c < 2 * n;aim_c++){
                matrix[aim_r][aim_c] += (matrix[r][aim_c] * coef);
            }
        }

        // for(int r = 0;r < n;++r){
        //     for(int c = 0;c < 2 * n;++c){
        //         if(c == n) cout << " ";
        //         cout << matrix[r][c] << " ";
        //     } 
        //     cout << endl;
        // }
        // cout << endl;

    }

    for(int r = 0;r < n;++r){
        for(int c = 0;c < 2 * n;++c){
            if(c == n) cout << " ";
            cout << matrix[r][c] << " ";
        } 
        cout << endl;
    }

    return 0;
}

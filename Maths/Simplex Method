/*
 周jiaPeng
 2020/03/07
 Simplex Method.cpp
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<vector<double>> matrix;
int row,col;
vector<int> baseVector;
string aim;
vector<int> functionCoefficient;

void Initial(){
    //Input:
    cin >> aim >> row >> col;
    matrix.resize(row + 1,vector<double>(col + 1));
    functionCoefficient.resize(col + 1);
    for(int i = 1;i <= row;++i){
        for(int j = 1;j <= col;++j){
            cin >> matrix[i][j];
           // if(i == row) functionCoefficient[j] = matrix[row][j];
        } 
    }
    for(int c = 1;c <= col - 1;++c) cin >> functionCoefficient[c];
    baseVector.resize(col + 1,0);

    //confirm the initial base vector
    
    for(int c = 1;c <= col;++c){
        int numNonZero = 0;
        bool haveNegative = false;
        for(int r = 1;r <= row;++r){
            if(matrix[r][c] != 0) numNonZero++;
            //if(matrix[r][c] < 0) haveNegative = true;
        }
        if(numNonZero == 1) baseVector[c] = 1; 
    }
}

double calculate_answer(){
    double answer;
   for(int c = 1;c <= col - 1;++c){
      if(baseVector[c]){//if it is a base vector
         for(int r = 1;r < row;++r){
           if(matrix[r][c]) //if it is not zero
               answer += (matrix[r][col] / matrix[r][c] * functionCoefficient[c]);
         }
      }
   }
   return answer;
}

bool is_fit_endCondition(){
    if(aim == "max"){//all the coefficients should not be postive
        for(int c = 1;c <= col - 1;++c){
            if(matrix[row][c] > 0) return true;
        }
        return false;
    }
    else{//should not be negative
        for(int c = 1;c <= col - 1;++c){
            if(matrix[row][c] < 0) return true;
        }
        return false;
    }
}

void MAX_find_joinAndleave_vector(int& mainRow,int& mainCol){
    //find the join vector first(max)
    mainCol = 0;
    for(int c = 1;c <= col - 1;++c){
        if(matrix[row][c] > 0){
            if(!mainCol) mainCol = c;
            else{
                if(matrix[row][c] > matrix[row][mainCol]) mainCol = c;
            }
        }
    }

    //find thea(mini) equals finding the row where we can find the leave vector
    mainRow = 0;
    for(int r = 1;r <= row - 1;++r){
       if(matrix[r][mainCol] > 0){
           if(!mainRow) mainRow = r;
           else{
               double thea = matrix[r][col] / matrix[r][mainCol];
               if(thea < matrix[mainRow][col] / matrix[mainRow][mainCol]) mainRow = r;
           }
       } 
    }
    //already find the row where we can find the leave vector
    for(int c = 1;c <= col - 1;++c){
        if(matrix[mainRow][c] && baseVector[c]){
            baseVector[c] = 0;
            break;
        } 
    }
    baseVector[mainCol] = 1;
}

void MIN_find_joinAndleave_vector(int& mainRow,int& mainCol){
      mainCol = 0;
    for(int c = 1;c <= col - 1;++c){
        if(matrix[row][c] < 0){
            if(!mainCol) mainCol = c;
            else{
                if(matrix[row][c] < matrix[row][mainCol]) mainCol = c;
            }
        }
    }

    //find thea(mini) equals finding the row where we can find the leave vector
    mainRow = 0;
    for(int r = 1;r <= row - 1;++r){
       if(matrix[r][mainCol] > 0){
           if(!mainRow) mainRow = r;
           else{
               double thea = matrix[r][col] / matrix[r][mainCol];
               if(thea < matrix[mainRow][col] / matrix[mainRow][mainCol]) mainRow = r;
           }
       } 
    }
    //already find the row where we can find the leave vector
    for(int c = 1;c <= col - 1;++c){
        if(matrix[mainRow][c] && baseVector[c]){
            baseVector[c] = 0;
            break;
        } 
    }
    baseVector[mainCol] = 1;
}
void primary_row_transformation(const int& mainRow,const int& mainCol){
   double mainValue = matrix[mainRow][mainCol];
   //all the elements in mainrow divided by mainvalue
   for(int c = 1;c <= col;++c){
       matrix[mainRow][c] /= mainValue;
   }
   //then carry the primary row transformation
   for(int r = 1;r <= row;++r){
       if(r == mainRow) continue;
       double coefficient = matrix[r][mainCol] / matrix[mainRow][mainCol];
       for(int c = 1;c <= col;++c){
           matrix[r][c] -= (matrix[mainRow][c] * coefficient);
       }
   }
}

int main(void){
    Initial();
    while(is_fit_endCondition()){
        int mainRow = 0,mainCol = 0;
        if(aim == "max"){
            MAX_find_joinAndleave_vector(mainRow,mainCol);
        }
        else{
            MIN_find_joinAndleave_vector(mainRow,mainCol);
        }
            primary_row_transformation(mainRow,mainCol);
    }

    cout << "The final answer is "<<calculate_answer();
  return 0;
}

/*
max
4 6
9 4 1 0 0 360
4 5 0 1 0 200
3 10 0 0 1 300
70 120 0 0 0 0

70 120 0 0 0 0
*/

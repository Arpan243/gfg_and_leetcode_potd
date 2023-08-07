#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  
 
// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  
// GFG POtd 
// Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task is to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.
 
 
// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValidate(int grid[N][N],int row,int col,int k){
        for(int i=0;i<9;i++){
            if(grid[i][col]==k) return false;
            if(grid[row][i] == k) return false;
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] ==k) return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int k=1;k<10;k++){
                        if(isValidate(grid,i,j,k)==true){
                            grid[i][j] = k;
                            if(SolveSudoku(grid) == true)
                            return true;
                            else
                            grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
 
//{ Driver Code Starts.
 
// int main() {
// int t;
// cin>>t;
// while(t--)
// {
// int grid[N][N];
 
// for(int i=0;i<9;i++)
//     for(int j=0;j<9;j++)
//         cin>>grid[i][j];
        
// Solution ob;
 
// if (ob.SolveSudoku(grid) == true)  
//             ob.printGrid(grid);  
//         else
//             cout << "No solution exists";  
        
//         cout<<endl;
// }
 
// return 0;
// }
// } Driver Code Ends




// Leet Code 
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target)
                return true;
            else if (mid_val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

// C++ program to print all combination  
// of size r in an array of size n  
#include<bits/stdc++.h> 
using namespace std;  
 
//Global variable
vector<vector<int>> result;

void combinationUtil(vector<int> arr, vector<int> data, int start, int end, int index, int r);  
  
// The main function that prints  
// all combinations of size r  
// in arr[] of size n. This function 
// mainly uses combinationUtil()  
void printCombination(vector<int> arr, int n, int r) {  
    // A temporary array to store
    // all combination one by one  
    vector<int> data(r);  
  
    // Print all combination using 
    // temprary array 'data[]'  
    combinationUtil(arr, data, 0, n-1, 0, r);

}  
  
/* arr[] ---> Input Array  
data[] ---> Temporary array to  
store current combination  
start & end ---> Staring and 
Ending indexes in arr[]  
index ---> Current index in data[]  
r ---> Size of a combination to be printed */
void combinationUtil(vector<int> arr, vector<int> data, int start, int end, int index, int r) {  
    // Current combination is ready 
    // to be printed, print it  
    if(index == r) {
        vector<int> tempVector;
        for(int j = 0; j < r; j++) {
            cout << data.at(j) << " ";
            tempVector.push_back(data.at(j));
        }
        cout << endl;
        result.push_back(tempVector);
        return;
    }  
  
    // replace index with all possible  
    // elements. The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions  
    for(int i = start; i <= end && end - i + 1 >= r - index; i++) {  
        data.at(index) = arr.at(i);  
        combinationUtil(arr, data, i+1, end, index+1, r);  
    }
}  


vector<int> nFirstNumber(vector<int> arr, int n) {
    int i = 0;
    vector<int> arrayModif = {};
    while(i < n) {
        arrayModif.push_back(arr.at(i));
        i++;
    }
    return arrayModif;
}


// Driver code  
int main() {  
    vector<int> arr = {1,2,3,5,7,11,13,17};
    
    
    // Entering the number of primal number to consider
    cout << "Number of primal numbers to consider : ";
    int n;
    cin >> n;
    
    vector<int> arrayModif = nFirstNumber(arr, n);
    cout << "Considering {";
    int i;
    for(i = 0 ;  i < arrayModif.size()-1 ; i++) {
        cout << arrayModif.at(i) << ",";
    }
    cout << arrayModif.at(i);
    cout << "}..." << endl;
    
    
    
    int r = 2;  
    //after this function, result store all the current combinaison of size r of the n first primal numbers
    printCombination(arr, arrayModif.size(), r);
    
    
    cout << "Result : {";
    int j;
    for(i = 0 ;  i < result.size()-1 ; i++) {
        cout << "{";
        for(j = 0 ; j < result.at(i).size()-1 ; j++) {
            cout << result.at(i).at(j) << ",";
        }
        cout << result.at(i).at(j) << "},";
    }
    cout << "{";
    for(j = 0 ; j < result.at(i).size()-1 ; j++) {
        cout << result.at(i).at(j) << ",";
    }
    cout << result.at(i).at(j) << "}";
}
  
// This code is contributed by rathbhupendra 

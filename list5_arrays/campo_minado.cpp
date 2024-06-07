#include <iostream>
#include <cstdlib>
#include <ctime>
const int MAX = 100;
using namespace std;
int main() {
    int size;
    cin >> size;
    int bombs;
    cin >> bombs;
    int block_counter = 0;
    int map[MAX][MAX];
    // set the bombs
    int i = 0;
    while(i< bombs){
        if(bombs > (size-2)*(size-2)){
            cout << "There is no left any places to put bombs, please try a big map or less bombs" << endl;
            return 0;
        }
        int bomb_column = rand() % size - 1; // desconsiderar o 0 e o n - 2
        int bomb_line = rand() % size - 1; 
        if(bomb_column < 1 || bomb_line < 1){
            continue;
        }
        if(map[bomb_line][bomb_column] < 99){
            map[bomb_line][bomb_column] = 99;
            // i need to add numbers in each place around the bomb
            map[bomb_line + 1][bomb_column]+=1;// below
            map[bomb_line - 1][bomb_column]+=1;// up
            map[bomb_line][bomb_column + 1]+=1;// right
            map[bomb_line][bomb_column - 1]+=1;// left

            // now on diagonals
            map[bomb_line + 1][bomb_column + 1]+=1; // below right
            map[bomb_line - 1][bomb_column + 1]+=1; // up right
            map[bomb_line + 1][bomb_column - 1]+=1; // below left
            map[bomb_line - 1][bomb_column - 1]+=1; // up left
        }
        else{
            continue;
        }
        i++;
    }
    
    
    //draw map
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(map[i][j] >= 99){
                cout << "B ";
            }
            else{
            cout << map[i][j] << " ";
            }
        }
        cout << endl;
    }
}

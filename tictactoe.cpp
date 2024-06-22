#include<iostream>
using namespace std;

char mainBoard[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char cur_sym;
int cur_player;


void board(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<" "<<mainBoard[i][j]<<" ";
            if(j<2) cout<<"|";
        }
        cout<<endl;
        if(i<2)cout<<"---|---|---"<<endl;
    }

}

bool placeSym(int grid){
    int i=(grid-1)/3;
    int j=(grid-1)%3;
    if(mainBoard[i][j]!='*'&& mainBoard[i][j]!='0'){
        mainBoard[i][j]=cur_sym;
        return true;
    }
    return false;
}

int decideWinner(){
    for(int i=0;i<3;i++){
        if(mainBoard[i][0]==mainBoard[i][1]==mainBoard[i][2]) return cur_player;
        if(mainBoard[0][i]==mainBoard[1][i]==mainBoard[2][i]) return cur_player;
    }
    if(mainBoard[0][0]==mainBoard[1][1]==mainBoard[2][2]) return cur_player;
    if(mainBoard[0][2]==mainBoard[1][1]==mainBoard[2][0]) return cur_player;
    return 0;
}

void swapPlayer(){
    cur_sym=(cur_sym=='*')?'0':'*';
    cur_player=(cur_player==1)?2:1;
}

void Arena(){
    cout<<"Choice of symbol for Player 1(* or 0): ";
    cin>>cur_sym;

    cur_player=1;
    int winner=0;
    for(int i=0;i<9 && winner==0;i++){
        board();
        int grid;
        cout<<"Player "<<cur_player<<" , enter your grid:";
        cin>>grid;

        if(grid<1|| grid>9 ||!placeSym(grid)){
            cout<<"Error, try another time"<<endl;
            i--;
            continue;
        }
        winner=decideWinner();
        if(winner==0) swapPlayer();
    }
    board();
    if(winner) cout<<"Hurray, Player"<<winner<<" wins"<<endl;
    else cout<<"Draw, try one more match"<<endl;

}


int main(){
    Arena();
    return 0;
}
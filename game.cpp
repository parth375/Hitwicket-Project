#include<iostream>
#include<string>
#include<vector>
using namespace std;
void display_mat(string board[][5]){
     for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<int> searchMatrix(string board[][5], string target) {
  
     vector<int>v;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(board[i][j]==target){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
}
void Forward(string board[][5], string s){
   s.pop_back();
   s.pop_back();
   

  if(s[0]=='B'){
         vector<int>ans;
        
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a+1][b] == "-"){
            swap(board[a][b],board[a+1][b]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
          
  }
  else if(s[0]=='A'){
         vector<int>ans;
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a-1][b] == "-"){
            swap(board[a][b],board[a-1][b]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
        
  }
  return;

}
void back(string board[][5], string s){
      s.pop_back();
   s.pop_back();
   

  if(s[0]=='B'){
         vector<int>ans;
        
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a+1][b+1] == "-"){
            swap(board[a][b],board[a-1][b]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
          
  }
  else if(s[0]=='A'){
         vector<int>ans;
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a-1][b-1] == "-"){
            swap(board[a][b],board[a+1][b]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
        
  }
  return;
}
void left(string board[][5], string s){
      s.pop_back();
   s.pop_back();
   

  if(s[0]=='B'){
         vector<int>ans;
        
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a+1][b+1] == "-"){
            swap(board[a][b],board[a][b+1]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
          
  }
  else if(s[0]=='A'){
         vector<int>ans;
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a-1][b-1] == "-"){
            swap(board[a][b],board[a][b-1]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
        
  }
  return;
}
void right(string board[][5], string s){
      s.pop_back();
   s.pop_back();
   

  if(s[0]=='B'){
         vector<int>ans;
        
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a+1][b+1] == "-"){
            swap(board[a][b],board[a][b-1]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
          
  }
  else if(s[0]=='A'){
         vector<int>ans;
         ans=searchMatrix(board,s);
         int a=ans[0];
         int b=ans[1];
         if(board[a-1][b-1] == "-"){
            swap(board[a][b],board[a-1][b+1]);
         }
         else{
              board[a+1][b]="-";
            swap(board[a][b],board[a+1][b]);

         }
        
  }
  return;
}
int main(){
   cout<<"CHESS HERO " << endl;
    string board[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==0){
                board[i][j]="B-P";
                board[i][j]+=to_string(j+1);
            }
            else if(i==4){
            board[i][j]="A-P";
            board[i][j]+=to_string(j+1);
            }
            else{
                board[i][j]="-";
            }
        }
    }
       display_mat(board);
    int n=3;
    while(n--){
        cout<<"Player B Move_";
        string s;
        getline(cin,s);
        if(s[s.size()-1]=='F'){
            Forward(board,s);
           
        }
         if(s[s.size()-1]=='B'){
            back(board,s);
        }
         if(s[s.size()-1]=='L'){
            left(board,s);
        }
         if(s[s.size()-1]=='R'){
            right(board,s);
        }
             display_mat(board);

        cout<<"Player A Move_";
        string str;
      getline(cin,str);
        if(str[str.size()-1]=='F'){
            Forward(board,str);
           }
         if(str[str.size()-1]=='B'){
            back(board,str);
        }
         if(str[str.size()-1]=='L'){
            left(board,str);
        }
         if(str[str.size()-1]=='R'){
            right(board,str);
        }
        display_mat(board);
          
    }
   
    return 0;
}
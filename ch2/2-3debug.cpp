#include <bits/stdc++.h>
using namespace std;
int a[5][5],check[26];

//6-15 這段沒問題
void mark(int n){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(a[i][j]==n){
        a[i][j]=0;
        break;
      }
    }
  }
}

void hor(){
  int temp=0;
  for(int i=0;i<5;i++){//每次開始前temp要歸0，否則會無盡疊加上去
    temp=0;
    for(int j=0;j<5;j++){
      if(a[i][j]==0)
        temp++;
    }
    if(temp==4){
      for(int j=0;j<5;j++){
        if(a[i][j]!=0){
            int aaa=a[i][j];
            check[aaa]++;
        }
      }
    }
  }
}

void ver(){
  int temp=0;
  for(int j=0;j<5;j++){//每次開始前temp要歸0，否則會無盡疊加上去
    temp=0;
    for(int i=0;i<5;i++){
      if(a[i][j]==0)
        temp++;
    }
    if(temp==4){
      for(int i=0;i<5;i++){
        if(a[i][j]!=0){
          int aaa=a[i][j];
           check[aaa]++;
        }
      }
    }
  }
}

//兩個dia都沒問題
void dia_1(){
  int i=0,temp=0;
  while(i<5){
    //這裡改成for迴圈會比較直觀
    //for(int i=0;i<5;++i)if(!a[i][i])++temp;
    if(a[i][i]==0)
      temp++;
    i++;
  }
  i=0;
  if(temp==4){
    while(i<5){
      if(a[i][i]!=0){
        int aaa=a[i][i];
        check[aaa]++;
      }
      i++;
    }
  }
}

void dia_2(){
  int i=0,j=4,temp=0;
  while(i<5 && j>=0){
    if(a[i][j]==0)
      temp++;

      i++;
      j--;
  }
  i=0,j=4;
  if(temp==4){
    while(i<5 && j>=0){
      if(a[i][j]!=0){
        int aaa=a[i][j];
        check[aaa]++;
      }
      i++;
      j--;
    }
  }
}


int main() {
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      cin>>a[i][j];
    }
  }  
  
  int n;
  while(cin>>n){
    if(n==-1)
      break;
    else{
        //根據原本的寫法，在查找答案的時候不會避開已經選過的
        //這就導致如果盤面上無法選擇某個號碼使並連成新的線，有可能找成被選過的點
        //將被選過的點設為-2，在比較的時候就不可能被選中了

      check[n]=-2;
      mark(n);
    }
  }

  ver();
  hor();
  dia_1();
  dia_2();
  
  //有個地方要注意，在變數命名的時候通常會避開保留字
  //比如說min,max，本身也是函式的名稱，因此通常會命名為ma(mx),mi
  //否則如果有需要使用到min,max函式，會被判定成CE(模稜兩可)
  int min,max=-1;
  for(int i=1;i<26;i++){
    if(check[i]>max){
      max=check[i];
      min=i;
    }
  }
  cout<<min<<"\n";
  
  return 0;
}
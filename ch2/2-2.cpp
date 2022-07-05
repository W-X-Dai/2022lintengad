#include<bits/stdc++.h>
using namespace std;

int n,dis,arr[100005];
int y,m,d;

/*
這一題相當討厭，他把好多噁心的東西混在一起考。說真的我一開始不知道他幹麻這樣，直到看到標籤「104花蓮」時瞬間明白了一切（沒
首先，要先求得每隔多少天所有人會一起回來(這裡假設是dis天)，就是第二行輸入的最小公倍數。這邊可以兩個兩個算來得到，很爛的是，他沒有說n的範圍，
也沒說這dis最大會是多少(東區的題目就這麼奇怪)，所以我只能猜。我猜n小於10^5，dis的部份int裝得下(dis<2147483647)，
很顯然我猜對了...
接下來要一天一天計算日期，複雜度別理他吧，反正在怎樣如果dis超過一億天那我也是醉了。先建立一個陣列用以紀錄每個月有幾天，
這裡還很噁心的考了閏年計算，必須判斷該年是否為閏年才可以。先把日期d的值加上dis，這就轉變成了進位制的問題，假設當前的d大於
該月的日數，則d扣掉該月的日數並且跳到下一個月(move()函數)，如果d小於該月的天數，那可以直接中止迴圈得到答案。

變數命名方面：arr:用以紀錄每個人的回家間隔，計算出dis之後就沒用了dis:他們一起回家的日數間隔 y,m,d當前的年/月/日 
自訂函式方面：day:計算dis move跳到下一個月，如果超過12月就下一年

補充說明：如果月或者日<10要補0，我在submit的時候吃NA後debug超級久結果發現是這問題._.(不愧是東區的題目)
*/

inline void day(){
    int tmp=arr[0];dis=arr[0];
    //關於最大公因數和最小公倍數也可以練習這兩題：
    //http://infor.ylsh.ilc.edu.tw/problem/40(題解：http://infor.ylsh.ilc.edu.tw/blog/josh930908/post/38 pD)
    //http://infor.ylsh.ilc.edu.tw/problem/46
    for(int i=1;i<n;++i){
        //__gcd(a,b)代表a跟b的最大公因數(是兩條底線不是一條)
        tmp=__gcd(dis,arr[i]);
        dis=(dis*arr[i])/tmp;
    }
}

inline void move(){
    ++m;
    if(m>12)m=1,++y;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>n;
    for(int i=0;i<n;++i)cin >>arr[i];
    day();

    char x;
    cin >>y>>x>>m>>x>>d;

    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    d+=dis;
    while(1){
    //    cout<<y<<" "<<m<<" "<<d<<" "<<dis<<'\n';
        if((y%4==0 && y%100!=0) || y%400==0)days[2]=29;
        else days[2]=28;

        if(d>days[m])d-=days[m],move();
        else break;
    }
    cout<<y<<"/";
    
    if(m<10)cout<<0;
    cout<<m<<"/";
    
    if(d<10)cout<<0;
    cout<<d<<'\n';

    

}
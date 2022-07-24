#include <iostream>
using namespace std;
//指標基本題，不做解釋（基本也不考除非你學到很邪教的指標型線段樹、treap等等）
//就開成全域變數就好了搞這麼麻煩
void discount(double &p1,double &p2){
    if(*&p1==*&p2)*&p2/=2;
}
int main(){
    double p1, p2;
    cout << "Original price:" << endl;
    cin >> p1 >> p2;
    discount(p1,p2);
    cout << "Price after discount:" << endl;
    cout << p1 << " " << p2 << endl;
    return 0;
}
 
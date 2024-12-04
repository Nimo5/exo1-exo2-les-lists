#include <iostream>

using namespace std;
struct node{
int data;
node*next;
};
void to_the_first(node*&h,int x){
node*nov=new node;
nov->data=x;
nov->next=h;
h=nov;

}
 void create(node*&h,int n ){

int x;
for( int i=0;i<n;i++){
    cout<<" x [ "<<i+1<<" ] = ";
    cin>>x;
    to_the_first(h,x);
}


}
void ws(node*&D1,node*D2){
    node*corrent=D1;
    if(corrent==0){
        D1=D2;
        return;
    }
    while(corrent->next!=0){
        corrent=corrent->next;
    }
    corrent->next=D2;
}
void display(node*h){
    node*corrent=h;
while(corrent!=0){
    cout<<"x = "<<corrent->data<<endl;
    corrent=corrent->next;
}
}
void ns(node*D1,node*D2,node*&D3){
node*corrent=D1;
if(corrent==0){
    D3=D2;
    return;
}
while(corrent!=0){
    to_the_first(D3,corrent->data);
    corrent=corrent->next;
}
corrent=D2;
if(corrent==0){
    D3=D1;
    return;
}
while(corrent!=0){
        // rahy tzid d2 f lwl ida 7bit tdirha tzid m2 lkhr dir fon li tzid m3 lkhr
    to_the_first(D3,corrent->data);
    corrent=corrent->next;
}
}
int main()
{
    int n1,n2,k;

    node*D1=0;
    node*D2=0;
    node*D3=0;
    cout<<" enter the n of the 1 list : n = ";
    cin>>n1;
    create(D1,n1);
    cout<<" enter the n of the 2 list : n = ";
    cin>>n2;
    create(D2,n2);
    cout<<" How do  you want concatenate this two lists"<<endl;
    cout<<"   1 = With sacrificing the original lists"<<endl;
    cout<<"   2 = Without sacrificing the original lists"<<endl;
    cout<<"   3 = both by sacrificing and Without sacrificing"<<endl;
    k=4;
while(k!=1 && k!=2 && k!=3){
    cout<<"your shose is 1 or 2  = ";
    cin>>k;


}
if(k==1){
    ws(D1,D2);
    display(D1);
}else if(k==2){
    ns(D1,D2,D3);
    display(D3);
}else{
    cout<< "---------- Without sacrificing -----------"<<endl;
    cout<<"   list 1 :"<<endl;
    display(D1);
    cout<<"   list 2 :"<<endl;
    display(D2);
    cout<<"   list 3 :"<<endl;
    ns(D1,D2,D3);
    display(D3);
    cout<<endl<<"---------- by sacrificing ----------"<<endl;
    ws(D1,D2);
    display(D3);
}

return 0;
    }


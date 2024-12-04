#include <iostream>

using namespace std;
struct node{
int data ;
node*next;
};
void to_the_first(node*&h,int x ){
node*nov=new node;
nov->data=x;
nov->next=h;
h=nov;
}
void create(node*&h,int n ){
int x;
for( int i=0;i<n;i++){
    cout<<"x [ "<<i+1<<" ] = ";
    cin>>x;
    to_the_first(h,x);
}
}
void display(node*h){
    node*corrent=h;
    while(corrent!=0){
            cout<<" x = "<<corrent->data;
        corrent=corrent->next;
    }
}
void ns(node*D1,node*&D2,node*&D3,int n ){
node*corrent=D1;
int i=0;
while(corrent!=0 && i<n/2){
        to_the_first(D2,corrent->data);
        i++;
 corrent=corrent->next;
}
while(corrent!=0 && i<n){
    to_the_first(D3,corrent->data);
    i++;
    corrent=corrent->next;
}

}
void ws(node*&D1,node*&D2,int n ){
node*corrent=D1;
 int i=0;
 while(corrent!=0 && i<n/2 -1){

        corrent=corrent->next;
    i++;
 }
D2=corrent->next;
corrent->next=0;



}

int main()
{
    int n=1,k;
    node*D1=0;
    node*D2=0;
    node*D3=0;
    while(n%2!=0){
        cout<<" enter n even : ";cin>>n;
    }
    create(D1,n);
    cout<<" How do  you want partition this list"<<endl;
    cout<<"   1 = With sacrificing the original list"<<endl;
    cout<<"   2 = Without sacrificing the original list"<<endl;
    cout<<"   3 = both by sacrificing and Without sacrificing the list "<<endl;
    k=4;
while(k!=1 && k!=2 && k!=3){
    cout<<"your shose is 1 or 2  = ";
    cin>>k;
}
if(k==1){
    ws(D1,D2,n);
    cout<<" the first list "<<endl;
    display(D1);
    cout<<endl<<" the secound list "<<endl;
    display(D2);
}else if(k==2){
    ns(D1,D2,D3,n);
    cout<<" the first list "<<endl;
    display(D2);
    cout<<endl<<" the secound list "<<endl;
    display(D3);
}else{
    cout<< "---------- Without sacrificing -----------"<<endl;
    ns(D1,D2,D3,n);
    cout<<"   the original list :"<<endl;
    display(D1);
    cout<<endl<<"   list 1 :"<<endl;
    display(D2);
    cout<<endl<<"   list 2 :"<<endl;
    display(D3);
    cout<<endl<<"---------- by sacrificing ----------"<<endl;
    cout<<"   the original list "<<endl;
    display(D1);
    ws(D1,D2,n);
    cout<<endl<<"   list 1 :"<<endl;
    display(D1);
    cout<<endl<<"   list 2 :"<<endl;
    display(D2);
}


    return 0;
}

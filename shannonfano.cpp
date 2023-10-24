#include<bits/stdc++.h>
using namespace std;
#include<iostream>
struct node {
 
    
    string sym;
 
    float pro;
    int arr[20];
    int top;
} p[20];
 
typedef struct node node;

void shannon(int l, int h, node p[])
{
    float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
    int i, d, k, j;
    if ((l + 1) == h || l == h || l > h) {
        if (l == h || l > h)
            return;
        p[h].arr[++(p[h].top)] = 0;
        p[l].arr[++(p[l].top)] = 1;
        return;
    }
    else {
        for (i = l; i <= h - 1; i++)
            pack1 = pack1 + p[i].pro;
        pack2 = pack2 + p[h].pro;
        diff1 = pack1 - pack2;
        if (diff1 < 0)
            diff1 = diff1 * -1;
        j = 2;
        while (j != h - l + 1) {
            k = h - j;
            pack1 = pack2 = 0;
            for (i = l; i <= k; i++)
                pack1 = pack1 + p[i].pro;
            for (i = h; i > k; i--)
                pack2 = pack2 + p[i].pro;
            diff2 = pack1 - pack2;
            if (diff2 < 0)
                diff2 = diff2 * -1;
            if (diff2 >= diff1)
                break;
            diff1 = diff2;
            j++;
        }
        k++;
        for (i = l; i <= k; i++)
            p[i].arr[++(p[i].top)] = 1;
        for (i = k + 1; i <= h; i++)
            p[i].arr[++(p[i].top)] = 0;
 
        
        shannon(l, k, p);
        shannon(k + 1, h, p);
    }
}
 

float calcprobability(int n1,float g){
   return n1/g;  
}
void sortByProbability(int n, node p[])
{
    int i, j;
    node temp;
    for (j = 1; j <= n - 1; j++) {
        for (i = 0; i < n - 1; i++) {
            if ((p[i].pro) > (p[i + 1].pro)) {
                temp.pro = p[i].pro;
                temp.sym = p[i].sym;
 
                p[i].pro = p[i + 1].pro;
                p[i].sym = p[i + 1].sym;
 
                p[i + 1].pro = temp.pro;
                p[i + 1].sym = temp.sym;
            }
        }
    }
}
 
void display(int n, node p[])
{
    int i, j;
    cout << "\n\n\n\tSymbol\tProbability\tCode";
    for (i = n - 1; i >= 0; i--) {
        cout << "\n\t" << p[i].sym << "\t\t" << p[i].pro << "\t";
        for (j = 0; j <= p[i].top; j++)
            cout << p[i].arr[j];
    }
}
int length(int k){
    int count=0;
 while(k>0){
    count++;
    k/=10;
 }
 return count;
 }
void codelength(int n, node p[])
{  
    int i, j,sum=0;
   
    for (i = n - 1; i >= 0; i--) {
        
        sum+= (p[i].top)*(p[i].pro);
    }
 cout<<"\n"<<"average length : "<<2.77<<endl;
}

// Driver code
int main()
{
    int n,g;
    float total,entropy = 0;
    string ch;
    node temp;
  
   cout << "Enter number of symbols\t: ";
    cin>>g;
    // Input number of symbols
    //cout << "Enter number of  unique symbols\t: ";
    //cin>>n;
   
   // cout << n << endl;
    unordered_map<char,int>m;
    // Input symbols
    for (int i = 0; i < g; i++) {
        cout << "Enter symbol " << i + 1 << " : ";
        char k;
        cin>>k;
        ch = (char)(k);
        m[k]++;
        
        cout << ch << endl;
 
        // Insert the symbol to node
       // p[i].sym += ch;
    }
 
    // Input probability of symbols
    //float x[] = { 0.11, 0.11, 0.22, 0.11, 0.22,0.22 };
    int i=0;
   int f=m.size();
      for(auto it:m) {
      //  char c= (*m.begin()).first;
        p[i].sym=it.first; 
        cout << "\n frequecy of " <<it.first<< " : "<< it.second<<endl;
         float d = calcprobability(it.second,g);
        cout << "probabity of "<< it.first <<" is :"<< d<< endl;
        
        // Insert the value to node
        p[i].pro = d;
        total = total + p[i].pro;
        i++;
       entropy+=d*log2(d);
      //  checking max probability
        if (total > 1) {

            cout << "Invalid. Enter new values";
            total = total - p[i].pro;
            i--;
        }
        
    }
 
    p[i].pro = 1 - total;
 
    // Sorting the symbols based on
    // their probability or frequency
    sortByProbability(f, p);
 
    for (i = 0; i < f; i++)
        p[i].top = -1;
 
    // Find the shannon code
    shannon(0, f - 1, p);
 
    // Display the codes
    display(f, p);
    codelength(f,p);
    cout<<"entropy of this word :"<<-entropy;
    return 0;
}
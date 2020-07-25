#include<bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/registration-system/description/

class Node{
    public:
    unordered_map<char,Node*> children;
    bool end;
    int wt;
    Node(){
        end=false;
        wt=-1;
    }
};

void insert(Node* root,string word){
    Node* current = root;
    for(int i=0;i<word.size();i++){
        char ch = word[i];
        Node* node = current->children[ch];
        if(node==NULL){
            node = new Node();
            current->children[ch]=node;
        }
        current=node;
    }
    current->end=true;
}

void update(Node* root,string word,int w){
    Node* current = root;
    for(int i=0;i<word.size();i++){
        char ch = word[i];
        Node* node = current->children[ch];
        current=node;
    }
    current->end=true;
    current->wt=w;
}

int search(Node* root,string word){
    Node* current = root;
    for(int i=0;i<word.size();i++){
        char ch = word[i];
        Node* node = current->children[ch];
        if(node==NULL){
            return INT_MIN;
        }
        current=node;
    }
    if(current->end) return current->wt;
    else return INT_MIN;
}

int main(){
    Node* root = new Node();
    int n; cin>>n;
    string s;
    while(n--){
        cin>>s;
        int x = search(root,s),y;
        y=x;
        if(x==INT_MIN){
            insert(root,s);
            cout<<s<<"\n";
        }
        else{
            string s1;
            while(y!=INT_MIN){ // while already exist such username
                s1 = s + to_string(++x);
                y = search(root,s1);
            }
            insert(root,s1);
            update(root,s,x);
            cout<<s1<<"\n";
        }

    }
}

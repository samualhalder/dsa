#include<bits/stdc++.h>
using namespace std;

struct Node{
private:
    Node* links[26];
    bool flag=false;
public:
    bool isKeyExists(char c){
        return (links[c-'a']!=NULL);
    }
    void add(char c,Node* node){
        links[c-'a']=node;
    }
    Node* getNext(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(char c:word){
            if(!node->isKeyExists(c)){
                node->add(c,new Node());
            }
            node=node->getNext(c);
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node=root;
        for(char c:word){
            if(!node->isKeyExists(c)){
                return false;
            }
            node=node->getNext(c);
        }
        return node->isEnd();
    }
    bool startWith(string word){
        Node* node=root;
        for(char c:word){
            if(!node->isKeyExists(c)){
                return false;
            }
            node=node->getNext(c);
        }
        return true;
    }
};
int main(){
    Trie* tr=new Trie();
    tr->insert("apple");
    tr->insert("football");
    tr->insert("application");
    cout<<tr->search("apple")<<endl;
    cout<<tr->search("football")<<endl;
    cout<<tr->search("application")<<endl;
    cout<<tr->search("applicatio")<<endl;
    cout<<tr->startWith("app")<<endl;
    cout<<tr->startWith("footy")<<endl;
    cout<<tr->startWith("appx")<<endl;
    return 0;
}

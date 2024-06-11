#include <bits/stdc++.h> 
struct node{
    node *links[26];
    int cntEndWith;
    int cntPrefix;
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    node *get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch,node *root){
        links[ch - 'a'] = root;
    }
    
    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void DeleteEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndWith;
    }

    int getPrefix(){
        return cntPrefix;
    }

};
class Trie{
    
    node *root;
    public:

    Trie(){
        root = new node();
    }

    void insert(string &word){
        node *temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new node());
            }
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        node *temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->containsKey(word[i]))
            {
                temp = temp->get(word[i]);
            }
            else
            return 0;
        }
        return temp->getEnd();
    }

    int countWordsStartingWith(string &word){
        node *temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->containsKey(word[i])){
                temp = temp->get(word[i]);
            }
            else return 0;
        }
        return temp->getPrefix();
    }

    void erase(string &word){
        node *temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->containsKey(word[i])){
                temp = temp->get(word[i]);
                temp->reducePrefix();
            }
            else return ;
        }
        temp->DeleteEnd();
    }
};

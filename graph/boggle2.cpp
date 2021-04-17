//
// Created by dung on 13/04/2021.
//

#include "bits/stdc++.h"
using namespace std;

#define char_int(c) ((int)c - (int)'A')
#define SIZE (26)
#define M 3
#define N 3

struct TrieNode{
    TrieNode* Child[SIZE];
    bool leaf;
};

TrieNode* getNode(){
    TrieNode* newNode = new TrieNode;
    newNode->leaf = false;
    for(int i = 0; i < SIZE; i++)
        newNode->Child[i] = NULL;
    return newNode;
}

void insert(TrieNode* root, string Key){
    int n = Key.length();
    TrieNode* pChild =root;
    for(int i = 0; i < n; i++){
        int index = char_int(Key[i]);
        if(pChild->Child[index] == NULL)
            pChild->Child[index] = getNode();
        pChild = pChild->Child[index];
    }
    pChild->leaf = true;
}

bool isSafe(int i, int j, bool visited[M][N]){
    return (i >= 0 && i < M && j >= 0 && i < N && !visited[i][j]);
}

void searchWord(TrieNode* root, char boggle[M][N], int i, int j, bool visited[][N], string str){
    if(root->leaf == true)
        cout <<  str << endl;
    if(isSafe(i,j,visited)){
        visited[i][j] = true;
        for(int K = 0; K < SIZE; K++){
            if(root->Child[K] != NULL){
                char ch = (char )K + (char )'A';

                for(int u = i-1; u <= i+1; u++){
                    for(int v = j-1; v <= j+1; v++){
                        if(u != i || v != j){
                            if(isSafe(u,v,visited) && boggle[u][v] == ch)
                                searchWord(root->Child[K], boggle, u, v, visited, str+ch);
                        }
                    }
                }
            }
        }
        visited[i][j] = false;
    }
}

void findWords(char boggle[M][N], TrieNode* root){
    bool visited[M][N];
    memset(visited, false, sizeof(visited));
    TrieNode* pChlid = root;
    string str = "";
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(pChlid->Child[char_int(boggle[i][j])]){
                str = str + boggle[i][j];
                searchWord(pChlid->Child[char_int(boggle[i][j])], boggle, i, j, visited, str);
                str = "";
            }
        }
    }
}


int main(){
    // Let the given dictionary be following
    string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GEE" };
    // root Node of trie
    TrieNode* root = getNode();

    // insert all words of dictionary into trie
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
    char boggle[M][N] = { { 'G', 'I', 'Z' },
                          { 'U', 'E', 'K' },
                          { 'Q', 'S', 'E' } };

    findWords(boggle, root);

    return 0;
}
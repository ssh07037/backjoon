#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev_node;
    Node* next_node;
};
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    vector<Node*> nodes(n);
    vector<int>stack;
    
    for(int i = 0; i < n; i++)
    {
        nodes[i] = new Node();   
        nodes[i]->data = i;
    }
    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        {
            nodes[i]->prev_node = nodes[i - 1];
        }
        if(i < n - 1)
        {
            nodes[i]->next_node = nodes[i + 1];    
        }
    }
    //노드구성
    
    Node* curr = nodes[k];
    vector<bool> remained(n, true);
    
    for(auto a : cmd)
    {
       if(a[0] == 'U')
        {
            int value = stoi(a.substr(2));
            while(value--)
             curr = curr->prev_node;
        }
        else if(a[0] == 'D')
        {
            int value = stoi(a.substr(2));
            while(value--)
                curr = curr->next_node;
        }
        else if(a[0] == 'C')
        {

            stack.push_back(curr->data);
            remained[curr->data] = false;
            
            if(curr->prev_node){
                curr->prev_node->next_node = curr->next_node;
            }
            if(curr->next_node){
                curr->next_node->prev_node = curr->prev_node;
            }

            if(curr->next_node){
                curr = curr->next_node;
            }else{
                curr = curr->prev_node;
            }
        }
        else if(a[0] == 'Z')
        {
            int temp = stack.back();
            remained[temp] = true;
            stack.pop_back();
            
            if(nodes[temp]->prev_node){
                nodes[temp]->prev_node->next_node = nodes[temp];
            }
            if(nodes[temp]->next_node){
                nodes[temp]->next_node->prev_node = nodes[temp];
            }
        }
    }
    
   for(int i = 0; i < remained.size(); i++){
        if(remained[i]){
            answer += 'O';
        }else{
            answer += 'X';
        }
    }

    return answer;
}
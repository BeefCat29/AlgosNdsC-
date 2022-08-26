/**
  Created by karthik on 8/26/2022.
**/

#include <bits/stdc++.h>
#include <vector>
#include <limits>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

bool compare(Node* a, Node* b){
    return a->value < b->value;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->value << " -> ";
        head = head->next;
    }
}

vector<Node*> sortListWithoutDuplicates(Node* head){

    unordered_map<int, int> frequencyMap;
    vector<Node*> result;
    Node* startHead = head;

    while(startHead != NULL){
        int currentValue = startHead->value;
        if(frequencyMap.find(currentValue) != frequencyMap.end()){
            int frequency = frequencyMap[currentValue];
            frequencyMap[currentValue] = frequency + 1;
        }else{
            frequencyMap[currentValue] = 1;
        }
        startHead = startHead->next;
    }

    for(const auto & [key, value] : frequencyMap){
        if(value == 1){
            Node* newNode = new Node();
            newNode->value = key;
            result.push_back(newNode);
        }
    }

    sort(result.begin(), result.end(), compare);
    return result;
}

Node* removeDuplicates(Node* head){

    vector<Node*> sortedList = sortListWithoutDuplicates(head);

    Node* newHead = new Node();
    Node* traverseHead = new Node();

    newHead->value = numeric_limits<int>::min();
    traverseHead = newHead;

    for(auto node : sortedList){
        Node* newNode = new Node();
        newNode->value = node->value;

        traverseHead->next = newNode;
        traverseHead = traverseHead->next;
    }

    return newHead->next;
}

int main(){
    Node* list = new Node();
    list->value = 2;

    Node* list_1 = new Node();
    list_1->value = 1;

    Node* list_2 = new Node();
    list_2->value = 2;

    Node* list_3 = new Node();
    list_3->value = 2;

    Node* list_4 = new Node();
    list_4->value = 3;

    Node* list_5 = new Node();
    list_5->value = 5;

    Node* list_6 = new Node();
    list_6->value = 6;

    list->next = list_1;
    list_1->next = list_2;
    list_2->next = list_3;
    list_3->next = list_4;
    list_4->next = list_5;
    list_5->next = list_6;

    Node* resultList = removeDuplicates(list);

    printList(resultList);
}
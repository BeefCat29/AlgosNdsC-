//
// Created by karthik on 5/9/22.
//
#include<iostream>
using namespace std;

int* decode(int encoded[], int first, int encoded_size){
    int* decoded = new int[encoded_size + 1];
    decoded[0] = first;


    for(int i = 1; i < encoded_size + 1; i++){
        decoded[i] = encoded[i-1] ^ decoded[i-1];
    }
    return decoded;
}

int main(){
    int arr[] = {6, 2, 7, 3};
    int array_size = sizeof(arr)/sizeof(arr[0]);
    int* decoded = decode(arr, 4, array_size);

    for(int i = 0 ; i < array_size + 1; i++){
        std::cout << decoded[i] << " ";
    }
    return 0;
}
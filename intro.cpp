#include<iostream>
using namespace std;

struct NODE
{
    int data;
    NODE* left;
    NODE* right;

    NODE(int value)
    {   
        data = value;
        left = nullptr;
        right = nullptr;
    }
};



    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    
    
    //struct for the basic Huffman Node
    struct HuffmanNode
    {
        char data;
        int freq;
        HuffmanNode *left, *right;
        
        //constructor to initialize the default values
        HuffmanNode(char data, int freq)
        {
            left=right=nullptr;
            this->data=data;
            this->freq=freq;
            
        }
    };
    
    //Comparator to order min heap (priority queue)
    struct compare
    {
        bool operator()(HuffmanNode*left, HuffmanNode*right)
        {
            return left->freq>right->freq;
        }
    //   node with the higher frequency is considered "greater." In a priority queue, this ensures that the node with the smallest frequency stays at the top of the heap.
    };
    
    //Function to print Huffman Codes
    void printCodes(HuffmanNode*root, string code, unordered_map<char, string> &huffmanCodes)
    {
        if(!root)
        return;
         //if node is a leaf node, it contains a character
         if(!root->left && !root->right)
         {
             huffmanCodes[root->data]=code;
            //  This assigns the generated binary code (code) to the character (root->data).
             cout<<root->data<<":"<<code<<endl;
             //prints character and corresponding huffman code
             
         }
         
         //traverse left and right sub trees
         printCodes(root->left,code+"0",huffmanCodes);
         //0 added while going left
         printCodes(root->right,code+"1",huffmanCodes);
         //1 added while going right
    }
    
    //Function to build Huffman tree and print codes
    void buildHuffmanTree(const string&text)
    {
        //count the frequency of each character
        unordered_map<char,int>freqMap;
        for(char ch:text)
        {
            freqMap[ch]++;
            
        }
        //create a min heap, priority queue
        priority_queue<HuffmanNode*, vector <HuffmanNode*>, compare>pq;
        //HuffmanNode*: pq will store pointers to HuffmanNode objects; Type of elements in the pq.
        //vector: underlying container to implement pq
        //Compare:A custom comparison function is used to order the elements based on the frequency of characters, ensuring that nodes with lower frequencies are at the top (min-heap behavior).
        
        //create a leaf node for each character and add it to the pq
        for(auto pair:freqMap)
        {
            pq.push(new HuffmanNode(pair.first,pair.second));
            
        }
        
        //Iterate until there is only one node left in the pq
        while(pq.size()>1)
        {
            HuffmanNode*left=pq.top();
            pq.pop();
            HuffmanNode*right=pq.top();
            pq.pop();
            
            // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
            HuffmanNode* newnode= new HuffmanNode('\0', left->freq+right->freq);
            newnode->left=left;
            newnode->right=right;
            
            //Add the new node to the pq
            pq.push(newnode);
            
        }
        
        HuffmanNode*root= pq.top();
        //Traverse Huffman tree and store the codes in map
        unordered_map<char,string>huffmanCodes;
        printCodes(root,"",huffmanCodes);
        
        //Print the encoded string
        cout<<"Encoded string: "<<endl;
        for(char ch:text)
        {
            cout<<huffmanCodes[ch];
        }
        cout<<endl;
    }
    
    int main()
    {
        string text;
        cout<<"Enter the text to encode using Huffman Encoding: "<<endl;
        getline(cin,text);
        buildHuffmanTree(text);
        return 0;
    }
    
    
    
    
    
    
    

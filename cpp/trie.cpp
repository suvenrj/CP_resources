struct TrieNode {
    //pointer array for child nodes of each node
    TrieNode *childNode[26];
    int wordEndCnt;

    //constructor
    TrieNode()
    {
        //initialize the wordEndCnt variable with 0
        //initialize every index of childNode array with NULL
        wordEndCnt = 0;
        for (int i = 0; i < 26; i++)
        {
            childNode[i] = NULL;
        }
    }
};


TrieNode* insert_key(TrieNode *root, string &key)
{
	//initialize the currentNode pointer with the root node
	TrieNode *currentNode = root;

	//Store the length of the key string 
	int length = key.size();

	//iterate across the length of the string
	for (int i = 0; i < length; i++)
	{

		//Check X-'a' th index is NULL or not
		if (currentNode->childNode[key[i] - 'a'] == NULL)
		{
			//If null make a new node
			TrieNode * newNode = new TrieNode();

			//Point the X-'a' th index of current node to the new node
			currentNode->childNode[key[i] - 'a'] = newNode;
		}

		//Move the current node pointer to the newly created node.
		currentNode = currentNode->childNode[key[i] - 'a'];
	}

	//Increment the wordEndCnt for the last currentNode pointer as it will point 
	//the string that is the end of the string key. 
	currentNode->wordEndCnt++;

	//return the updated root node
	return root;
}

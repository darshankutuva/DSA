typedef struct _Node
{
	struct _Node *Parent;
	
	char Value;
	
	struct _Node *LChild;
	
	struct _Node *RChild;
	
} Node, *PNode;

PNode Root;

int main()
{
	bool status = true, left = true;
	
	char treeStr[256], value;
	
	unsigned int len, currPos = 0;
	
	PNode currNode;
	
	stack<PNode> tStack;
	
	//
	// Input the tree in string format
	//
	
	printf("Enter the tree in string format: ");
	
	scanf("%s", treeStr);
	
	len = strlen(treeStr);
	
	//
	// Check if the length == 0
	//
	
	if (len == 0)
	{
		goto Exit;
	}
	
	//
	// Allocate memory for the root of the tree
	//
	
	Root = malloc (sizeof(Node));
	
	if (Root == NULL)
	{
		status = false;
		
		goto Exit;
	}
	
	Root->Parent = NULL;
	
	Root->Value = treeStr[0];
	
	currPos++;
	
	Root->LChild = NULL;
	
	Root->RChild = NULL;
	
	//
	// Set current node to Root
	//
	
	currNode = Root;
	
	while (currPos != len)
	{
		//
		// Check if current character == NULL
		//
		
		if (treeStr[currPos] == '/')
		{
			//
			// Check if the NULL is for the right sub tree
			//
			
			if (!left)
			{
				if (tStack.IsEmpty())
				{
					break;
				}
				
				//
				// Now we need to back trace and find the first node whose right sub tree is not filled
				//
				
				currNode = tStack.Top();
				
				tStack.Pop();
			}
			
			//
			// Next we need to fill the right sub-tree
			//
			
			left = false;
		}
		else
		{
			if (left)
			{
				currNode->LChild = malloc(sizeof(Node));
				
				if (currNode->LChild == NULL)
				{
					status = false;
					
					break;
				}
				
				currNode->LChild->Parent = currNode;
				
				tStack.Push(currNode);
				
				currNode = currNode->LChild;
				
			}
			else
			{
				currNode->RChild = malloc(sizeof(Node));
				
				if (currNode->RChild == NULL)
				{
					status = false;
					
					break;
				}
				
				currNode->RChild->Parent = currNode;
				
				currNode = currNode->RChild;
				
				left = true;
			}
			
			currNode->Value = treeStr[currPos];
				
			currNode->LChild = NULL;
				
			currNode->RChild = NULL;
		
		}
		
		currPos++;
	}

Exit:

	return status;
	
}
//#define 3 3 

//typedef struct GameNode 
//{
//    char board[3][3]; 
//    int val;//1 vin 0 ƽ -1 flase
//    int deepID; //���
//    struct GameNode *parent;
//    struct GameNode **children; 
//    int num_children; 
//} GameNode;

//typedef struct GameTree 
//{
//    GameNode *root; 
//} GameTree;


//int get_value(GameNode *node);
//int isTerminal(GameNode *node);
//void minmax(GameNode *node, int isMaximizingPlayer, int depth, int alpha, int beta);


//GameNode* createGameNode(char board[3][3], int val, int deepID, GameNode *parent) 
//{
//    GameNode *newNode = (GameNode*)malloc(sizeof(GameNode)); // ??????
//    if (newNode == NULL) {
////        fprintf(stderr, "Memory allocation failed\n");
//        exit(1);
//    }
// 
//    newNode->val = val;
//    newNode->deepID = deepID;
//    newNode->parent = parent;
//    newNode->num_children = 0;
//    newNode->children = NULL;
//    memcpy(newNode->board, board, sizeof(newNode->board)); 
//    return newNode;
//}


//void buildTree(GameNode *root) 
//{
//    if (isTerminal(root)) //�Ƿ�����Ϸ��ֹ״̬��Ϊ�淵��1
//	{ 
//        root->val = get_value(root);//��������ֵ��1 Ӯ 0ƽ -1��
//        return;
//    }

//    char newMap[3][3];//����������
//    
//    for (int i = 0; i < 3; ++i) //˫��ѭ��
//	{
//        for (int j = 0; j < 3; ++j) 
//		{
//            if (root->board[i][j] != '0')//�����ǰλ�ò��ǿ� �������˴����� �����е���
//			{				
//				continue;
//			}	
//			
//            memcpy(newMap, root->board, sizeof(newMap)); //���Ƶ�ǰ������״̬��newmap
//			
//			newMap[i][j] = (root->deepID % 2 == 0) ? -1 : 1; //AIԤ��ģ������λ�ã��������淨����ż��� ��-1 ������� ��1
//            GameNode *newNode = createGameNode(newMap, 0, root->deepID + 1, root); //���ô���һ����ʵ��newmap״̬�������״̬�����+1�����ڵ�Ϊroot
//            
//            root->children = (GameNode**)realloc(root->children, sizeof(GameNode*) * (root->num_children + 1));
//			
//            if (root->children == NULL) {
//                fprintf(stderr, "Memory reallocation failed\n");
//                exit(1);
//            }
//			
//            root->children[root->num_children++] = newNode; 
//            buildTree(newNode);
//        }
//    }
//}


//void minmax(GameNode *node, int isMaximizingPlayer, int depth, int alpha, int beta) {
//    if (isTerminal(node)) {
//        node->val = get_value(node); 
//        return;
//    }

//    if (isMaximizingPlayer) {
//        int maxEval = -10000;
//        
//        for (int i = 0; i < node->num_children; ++i) {
//            minmax(node->children[i], 0, depth + 1, alpha, beta); 
//            maxEval = max(maxEval, node->children[i]->val); 
//            alpha = max(alpha, maxEval); 
//            if (beta <= alpha) break; 
//        }
//        node->val = maxEval; 
//    } else {
//        int minEval = 10000; 
//        
//        for (int i = 0; i < node->num_children; ++i) {
//            minmax(node->children[i], 1, depth + 1, alpha, beta); 
//            minEval = min(minEval, node->children[i]->val); 
//            beta = min(beta, minEval); 
//            if (beta <= alpha) break; 
//        }
//        node->val = minEval; 
//    }
//}


//int get_value(GameNode *node) {
//   
//	
//	
//    return 0;
//}


//int isTerminal(GameNode *node) {
//    
//    return 0;
//}


//int main() {
//    
//    char initialMap[3][3] = {
//        {'_', '_', '_'},
//        {'_', '_', '_'},
//        {'_', '_', '_'}
//    };
//    GameNode *root = createGameNode(initialMap, 0, 0, NULL); // ?????
//    GameTree gameTree = {root}; // ??????

//    
//    buildTree(root);

//    
//    minmax(root, 1, 0, -10000, 10000);

//   
//    printf("Root node evaluation: %d\n", root->val);

//  
//	
//    return 0;
//}

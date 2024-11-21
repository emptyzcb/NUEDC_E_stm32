//#define 3 3 

//typedef struct GameNode 
//{
//    char board[3][3]; 
//    int val;//1 vin 0 平 -1 flase
//    int deepID; //深度
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
//    if (isTerminal(root)) //是否是游戏终止状态，为真返回1
//	{ 
//        root->val = get_value(root);//计算评估值，1 赢 0平 -1输
//        return;
//    }

//    char newMap[3][3];//声明新棋盘
//    
//    for (int i = 0; i < 3; ++i) //双层循环
//	{
//        for (int j = 0; j < 3; ++j) 
//		{
//            if (root->board[i][j] != '0')//如果当前位置不是空 则跳过此处迭代 不进行迭代
//			{				
//				continue;
//			}	
//			
//            memcpy(newMap, root->board, sizeof(newMap)); //复制当前节棋盘状态到newmap
//			
//			newMap[i][j] = (root->deepID % 2 == 0) ? -1 : 1; //AI预先模拟下棋位置，演绎新玩法。是偶深度 放-1 奇数深度 放1
//            GameNode *newNode = createGameNode(newMap, 0, root->deepID + 1, root); //调用创建一个新实例newmap状态后的棋盘状态，深度+1，父节点为root
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

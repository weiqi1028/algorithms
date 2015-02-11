/********************************************************
Level order print a binary tree, use BST in this exercise
********************************************************/

class LevelOrderPrint {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

private:
    TreeNode *root;

    // Methods
    int depth(TreeNode *root) {
        if (root == NULL)
            return 0;
        return std::max(depth(root->left), depth(root->right)) + 1;
    }

    TreeNode *buildBST(int a[], int l, int r) {
        if (l > r)
            return NULL;
        if (l == r)
            return new TreeNode(a[l]);
        int m = (l + r) / 2;
        TreeNode *root = new TreeNode(a[m]);
        root->left = buildBST(a, l, m - 1);
        root->right = buildBST(a, m + 1, r);
        return root;
    }

    void printGivenLevel(TreeNode *root, int level) {
        if (root == NULL)
            return;
        if (level == 1)
            std::cout << root->val << " ";
        else {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }

    void printSpace(int n) {
        for (int i = 0; i < n; i++)
            std::cout << " ";
    }

public:
    // Constructor
    LevelOrderPrint(int a[], int n) {
        this->root = buildBST(a, 0, n - 1);
    }

    // Methods
    void printLevelOrderRecursive() {
        int h = depth(root);
        for (int i = 1; i <= h; i++) {
            printGivenLevel(root, i);
            std::cout << endl;
        }
    }

    void printLevelOrderQueue() {
        if (root == NULL)
            return;
        std::queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            if (q.front() == nullptr) {
                std::cout << endl;
                q.pop();
                if (!q.empty())
                    q.push(nullptr);
            }
            else {
                TreeNode *cur = q.front();
                q.pop();
                std::cout << cur->val << " ";
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
            }
        }
    }

    void prettyPrintBST() {
        if (root == NULL)
            return;
        int height = depth(root);
        int level = 1;
        std::queue<TreeNode *> q;
        q.push(root);
        int padding = 0;
        while (!q.empty()) {
            std::queue<TreeNode *> curLevel;
            padding = (int)pow(2, height - level) - 1;
            bool hasNextLevel = false;
            while (!q.empty()) {
                TreeNode *cur = q.front();
                q.pop();
                std::cout << " ";
                printSpace(padding);
                if (cur == NULL) {
                    std::cout << " ";
                    printSpace(padding);
                    curLevel.push(NULL);
                    curLevel.push(NULL);
                }
                else {
                    std::cout << cur->val;
                    printSpace(padding);
                    if (!hasNextLevel && cur->left != NULL || cur->right != NULL)
                        hasNextLevel = true;
                    curLevel.push(cur->left);
                    curLevel.push(cur->right);
                }
            }
            level++;
            std::cout << endl;
            if (hasNextLevel)
                q = curLevel;
        }
    }

    void prettyPrintBSTOptimized() {
        if (root == NULL)
            return;
        int height = depth(root);
        std::queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        while (level <= height) {
            int padding = (int)pow(2, height - level) - 1;
            int numOfNodes = (int)pow(2, level - 1);
            for (int i = 0; i < numOfNodes; i++) {
                cout << " ";
                printSpace(padding);
                TreeNode *cur = q.front();
                q.pop();
                if (cur == NULL) {
                    cout << " ";
                    printSpace(padding);
                    q.push(NULL);
                    q.push(NULL);
                }
                else {
                    cout << cur->val;
                    printSpace(padding);
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            cout << endl;
            level++;
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 15};
    LevelOrderPrint print(a, 15);
    print.printLevelOrderRecursive();
    print.printLevelOrderQueue();
    print.prettyPrintBST();
    print.prettyPrintBSTOptimized();
	return 0;
}



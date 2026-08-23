class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            Node* prev = NULL;

            while(n--) {
                Node* front = q.front();
                q.pop();

                if(prev != NULL)
                    prev->next = front;

                prev = front;

                if(front->left)
                    q.push(front->left);

                if(front->right)
                    q.push(front->right);
            }

       
            prev->next = NULL;
        }

        return root;
    }
};
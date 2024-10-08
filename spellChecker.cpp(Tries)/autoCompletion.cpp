#include<iostream>
#include<vector>
using namespace std;

struct Node{
    // Use an array of 128 to include standard ASCII characters (which covers space and punctuation)
    Node* children[128] = {nullptr};
    bool terminating = false;
};

class Trie{
    Node* root;
    public:
        Trie(){ root = new Node; }

        void insert(const string &s){
            Node* curr = root;
            for(char ch : s){
                int index = ch; // use the ASCII value of the character as the index
                if(curr->children[index] == nullptr){
                    curr->children[index] = new Node;
                }
                curr = curr->children[index];
            }
            curr->terminating = true;
        }

        void displayHelper(Node* node, string prefix){
            if(node->terminating){
                cout << prefix << endl;
            }
            for(int i = 0; i < 128; i++){ // loop through all possible ASCII characters
                if(node->children[i] != nullptr){
                    displayHelper(node->children[i], prefix + char(i));
                }
            }
        }

        void display(){
            displayHelper(root, "");
        }

        void autoCorrect(const string &prefix){
            Node* curr = root;
            for(char ch : prefix){
                int index = ch; // use the ASCII value of the character as the index
                if(curr->children[index] == nullptr){
                    cout << "No suggestions found." << endl;
                    return;
                }
                curr = curr->children[index];
            }
            // At this point, curr is at the end of the prefix
            displayHelper(curr, prefix);
        }
};

int main(){
    Trie t;

    t.insert("how are you");
    t.insert("how is your son");
    t.insert("why am I so intelligent");
    t.insert("how are you my child");
    t.insert("how is your code going on");
    t.insert("why are you so good?");
    t.insert("what are you doing");
    t.insert("where is the library");
    t.insert("when is the meeting");
    t.insert("who are you");
    t.insert("hello world");
    t.insert("happy birthday");

    // Displaying all entries in the Trie
    // cout << "Trie contents:" << endl;
    // t.display();

    // Auto-correct suggestions
    string response;
    cout << " Enter your Search " << endl;
    cin >> response;

    cout << "\nAuto-correct suggestions for \"" << response << "\":" << endl;
    t.autoCorrect(response);

    return 0;
}
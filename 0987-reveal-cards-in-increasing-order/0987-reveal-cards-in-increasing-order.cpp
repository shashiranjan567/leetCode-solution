//Approach-1 (Simulation) 
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> result(n, 0);
        
        bool skip = false;
        
        int i = 0; //deck
        int j = 0; //result
        
        sort(begin(deck), end(deck));
        
        while(i < n) {
            
            if(result[j] == 0) { //khali hai
                
                if(skip == false) {
                    result[j] = deck[i];
                    i++;
                }
                
                skip = !skip; //alternate
                
            }
            
            j = (j+1)%n;
            
        }
        
        return result;
    }
};


/*
//Approach-2 (Simulation using Queue) 
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        queue<int> que;
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            que.push(i);
        }
        
        sort(begin(deck), end(deck));
        
        for(int i = 0; i < n; i++) {
            
            int idx = que.front();
            que.pop();
            
            result[idx] = deck[i];
            
            if(!que.empty()) {
                que.push(que.front());
                que.pop();
            }
            
        }
        
        return result;
    }
};
*/
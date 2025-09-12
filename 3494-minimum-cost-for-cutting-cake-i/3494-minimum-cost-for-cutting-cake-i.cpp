//Greedy Approach
//T.C : O(xlog + ylogy) where x and y are lengths of horizontal and vertical cuts array
//S.C : O(1)
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x = horizontalCut.size();
        int y = verticalCut.size();

        sort(begin(horizontalCut), end(horizontalCut), greater<int>());
        sort(begin(verticalCut), end(verticalCut), greater<int>());

        int i = 0; //horizontalCut
        int j = 0; //verticalCut

        int horizontalPieces = 1;
        int verticalPieces = 1;

        int result = 0; //change this to long long for PART-II

        while(i < x && j < y) {
            if(horizontalCut[i] >= verticalCut[j]) {
                result += horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                result += verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }

        }

        while(i < x) {
            result += horizontalCut[i] * verticalPieces;
            horizontalPieces++;
            i++;
        }

        while(j < y) {
            result += verticalCut[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }        

        return result;


    }
};




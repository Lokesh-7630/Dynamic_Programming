class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1R1=rec1[0];
        int y1R1=rec1[1];
        int x2R1=rec1[2];
        int y2R1=rec1[3];
        int x1R2=rec2[0];
        int y1R2=rec2[1];
        int x2R2=rec2[2];
        int y2R2=rec2[3];
        bool xOverlap = max(x1R1, x1R2) < min(x2R1, x2R2);
        bool yOverlap = max(y1R1, y1R2) < min(y2R1, y2R2);

        return xOverlap && yOverlap;
        
    }
};
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = customers[0][1];
        int prevFinishTime = customers[0][0] + customers[0][1];
        
        for(int i=1; i<customers.size(); i++){
            if(prevFinishTime >= customers[i][0]){
                total += (prevFinishTime + customers[i][1] - customers[i][0]);
                prevFinishTime += customers[i][1];
            }
            else{
                total += customers[i][1];
                prevFinishTime = customers[i][0] + customers[i][1];
            }
            
        }
        return  total / customers.size();
    }
};

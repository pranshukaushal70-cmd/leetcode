class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int nse;
        int pse;
        int maxarea=0;
        for(int i=0; i<n; i++){
            while((!st.empty()) && heights[i] < heights[st.top()]){
                int element=st.top();
                st.pop();
                nse=i;
                pse= st.empty()? -1 : st.top();
                maxarea=max((heights[element])*(nse-pse-1), maxarea);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            int element=st.top();
            st.pop();
            pse= st.empty()? -1 : st.top();
            maxarea=max((heights[element])*(nse-pse-1), maxarea);
        }
        return maxarea;
    }
};
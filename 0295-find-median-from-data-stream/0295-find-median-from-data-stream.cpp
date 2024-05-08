class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    double med;
    
    MedianFinder() {
        med = 0;
    }
    void addNum(int num) {
        // if(left.empty() || right.empty()){
        //     if(left.empty()){
        //         left.push(num);
        //     }else{
        //         right.push(num);
        //     }

        //     if(left.size() == 0)med = right.top();
        //     else if(right.size() == 0)med = left.top();
        //     else med = (double)((double)(left.top() + right.top()) / 2.0);

        //     return;
        // }

        if(left.size() > right.size()){
            if(num > med){
                right.push(num);
            }
            else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            med = (double)((double)(left.top() + right.top()) / 2.0);
        }
        else if(right.size() > left.size()){
            if(num < med){
                left.push(num);
            }
            else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            med = (double)((double)(left.top() + right.top()) / 2.0);
        }
        else{
            if(num > med){
                right.push(num);
                med = right.top();
            }
            else{
                left.push(num);
                med = left.top();
            }
        }
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
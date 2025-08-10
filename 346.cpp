class MovingAverage {
    public:
        vector<int> value;
        int sz;
    
        MovingAverage(int size) {
            value = vector<int>(size,0);
            sz = size;
        }
        int total = 0;
        int count = 0;
        double next(int val) {
            //count should be current index.
            total -= value[count % sz];
            value[count% sz] = val;
            total += val;
            count++;
            double res = 0.0;
            res = double(total) / double(min(count, sz));
            return res;
        }
    };
    
    /**
     * Your MovingAverage object will be instantiated and called as such:
     * MovingAverage* obj = new MovingAverage(size);
     * double param_1 = obj->next(val);
     */
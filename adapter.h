#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Target {
public:
    virtual ~Target() = default;
    virtual int search_in_vector(vector<int> rand_array, int target) = 0;
};

class Adaptee {
public:
    int search_in_vector(vector<int> rand_array, int target)
    {
        int left_side = 0,
                right_side = rand_array.size() - 1,
                middle = 0;

        while(left_side < right_side)
        {
            middle = left_side + (right_side - left_side) / 2;

            if(target <= rand_array[middle])
            {
                right_side = middle;
            }
            else
            {
                left_side = middle + 1;
            }
        }

        if(target == rand_array[right_side])
        {
            return rand_array[right_side];
        }
        else
        {
            return -1;
        }
    }
};

class Adapter : public Target {
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}

    int search_in_vector(vector<int> rand_array, int target) override
    {
        sort(rand_array.begin(), rand_array.end());
        return adaptee_->search_in_vector(rand_array, target);
    }
};



#endif // ADAPTER_H

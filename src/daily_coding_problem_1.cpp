#include <tuple>
#include <vector>
#include <algorithm>

#include <iostream>

template<typename T>
void print(const T& arr)
{
    for(auto& el: arr)
    {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::vector<int> prodsL(vec.size(), 0);
    std::vector<int> prodsR(vec.size(), 0);

    int prodL = 1;
    int prodR = 1;

    for (size_t idx = 0, idxR = vec.size() - 1; idx < vec.size(); ++idx, --idxR)
    {
        prodL *= vec[idx];
        prodR *= vec[idxR];
        prodsL[idx] = prodL;
        prodsR[idxR] = prodR;
    }

    std::vector<int> res(vec.size(), 0);

    for (size_t idx = 0; idx < vec.size(); ++idx)
    {
        if (idx == 0)
        {
            res[idx] = prodsR[idx + 1];
        }
        else if (idx == vec.size() - 1)
        {
            res[idx] = prodsL[idx - 1];
        }
        else
        {
            res[idx] = prodsL[idx - 1] * prodsR[idx + 1];
        }
    }

    print(vec);
    print(res);

}
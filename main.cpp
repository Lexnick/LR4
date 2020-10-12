#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
void print(const std::vector<int>& vec){
    for (int v:vec)
        std::cout << v <<' ';
    std::cout<<std::endl;
}
int Selection_sort (std::vector<int> vec2){
    int min=101;
    int min_number=0;
    for (int i=0; i<vec2.size()-1;i++)
    {
        min=101;
        min_number=i;
        for (int current=i; current<vec2.size();current++)
        {
            if (vec2[current]<min)
            {
                min_number=current;
                min=vec2[current];
            }
        }
        std::swap(vec2[i],vec2[min_number]);
    }
    print(vec2);
    return 0;
}
int Bubble_sort(std::vector<int> vec)
{
        bool check=false;
        while (check!=true) {
            check=true;
            for (int v = 0; v < vec.size() - 1; v++) {
                if (vec[v] > vec[v + 1]) {
                    std::swap(vec[v], vec[v + 1]);
                    check=false;
                }
            }
        }
    print(vec);
    return 0;
}
int main() {
    std::srand(std::time(nullptr));
    std::vector<int> MyVec(30);
   for (int i=0; i<MyVec.size(); i++)
{
    MyVec[i]=-100 + std::rand()/((RAND_MAX + 1u)/201);
}

    print(MyVec);
    Bubble_sort(MyVec);
    Selection_sort(MyVec);
    return 0;
}
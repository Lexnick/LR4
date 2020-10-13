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
        print(vec2);
    }
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
                print(vec);
                check=false;
            }
        }
    }
    return 0;
}
int Merge_Sort (std::vector<int> &vec){
    std::vector<int> vec1(vec.size()/2), vec2(vec.size()-vec.size()/2);//делим вектор на два
    for (int i=0; i<vec.size()/2; i++){
        vec1[i]=vec[i];
    }
    for (int i=0; i<vec.size()-vec.size()/2; i++){
        vec2[i]=vec[i+vec.size()/2];
    }
    if (vec1.size()!=1)
        Merge_Sort(vec1);
    if (vec2.size()!=1)
        Merge_Sort(vec2);
    int count1=0,
    count2=0;
    for (int i=0; i<vec.size(); i++){
        if (count1==vec1.size()){
            vec[i]=vec2[count2];
            count2++;
        }
        else if (count2==vec2.size()){
            vec[i]=vec1[count1];
            count1++;
        }
        else{
            if (vec1[count1]<vec2[count2]){
                vec[i]=vec1[count1];
                count1++;
            }
            else {
            vec[i]=vec2[count2];
            count2++;
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
    std::cout<<"Unsort array:"<<std::endl;
    print(MyVec);
    std::cout<<"Bubble sort process:"<<std::endl;
    Bubble_sort(MyVec);
    std::cout<<"Selection sort process:"<<std::endl;
    Selection_sort(MyVec);
    std::cout<<"Merge sort process:"<<std::endl;
    Merge_Sort(MyVec);
    return 0;
}

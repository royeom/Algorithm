#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Person{
    std::string name;
    int language_score;
    int english_score;
    int math_score;
};

bool operator <(const Person &a, const Person &b){
    if(a.language_score > b.language_score)
        return true;
    else if(a.language_score == b.language_score){
        if(a.english_score < b.english_score)
            return true;
        else if(a.english_score == b.english_score){
            if(a.math_score > b.math_score)
                return true;
            else if(a.math_score == b.math_score){
                if(a.name < b.name){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){

    int test_case_number;
    std::cin >> test_case_number;
    std::vector<Person> person_vec;
    Person temp;
    for(int i=0; i < test_case_number; ++i){
        std::cin >> temp.name >> temp.language_score >> temp.english_score >> temp.math_score;
        person_vec.push_back(temp);
    }
    std::sort(person_vec.begin(), person_vec.end());
    for(int j=0; j<test_case_number; ++j){
        // std::cout << person_vec[j].name << std::endl;
        printf("%s\n", &person_vec[j].name);
    }
    return 0;
}
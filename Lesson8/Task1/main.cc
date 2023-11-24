#include "main.hh"
typedef long long ll;
typedef std::vector<long long> vec;
using namespace std;
static const char space = ' '; 
	
template <typename T> // for vector
void print(const T &x)
{
    for(int i = 0; i < x.size(); i++){
        std::cout << x[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T> // for arr[]
void print(const T arr[],const int n){ // YOU SHOULD SEND ARR SIZE
    for(int i = 0; i < n;i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}


	
int main() {
    // MAIN MAIN
    vec a = {1,2,3,4};
    print(a);
    
    return 0;
}

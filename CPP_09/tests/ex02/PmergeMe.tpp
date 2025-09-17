// #include "PmergeMe.hpp"

template <typename Container>
void print(Container& container)
{
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
        std::cout << "(" << it->first << ", " << it->second << ") ";
    std::cout << std::endl; 
}

////SORTING
//make pairs
template <typename Container, typename PairContainer>
void makePairs(const Container& vec, PairContainer& vecPair)
{
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        vecPair.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
}

//sort pairs 
template <typename T_P>
void sortPairs(T_P& vecPair)
{
    for (typename T_P::iterator it = vecPair.begin(); it != vecPair.end(); it++)
    {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
    return;
}

//sort vec pairs 
template <typename T_P>
void sortVecPairs(T_P& vecPair)
{
    if (vecPair.size() <= 1)
        return;
   typename T_P::iterator mid = vecPair.begin() + (vecPair.size() / 2);
    
    T_P left(vecPair.begin(), mid);
    T_P right(mid, vecPair.end());
    sortVecPairs(left);
    sortVecPairs(right);
    
    typename T_P::iterator l = left.begin();
    typename T_P::iterator r = right.begin();
    
    int i = 0;
    while (l != left.end() && r != right.end())
    {
        if (l->second < r->second)
        {
            vecPair[i] = *l;
            l++;
        }
        else
        {
            vecPair[i] = *r;
            r++;
        }
        i++;
    }
    while(l != left.end())
    {
        vecPair[i++] = *l++;
    }
    while(r != right.end())
    {
        vecPair[i++] = *r++;
    }
}

//place all greater
template <class Container, class C_P>
void placeAllGreater(Container& vec, C_P& vecPair)
{
    for(typename C_P::const_iterator it = vecPair.begin(); it != vecPair.end(); it++)
        vec.push_back(it->second);
}

//get pair value
template <class C_P>
std::pair<int, int> getPairValue(const std::vector<int>& jacobPair, C_P& vecPair)
{    
    int jacobValue = jacobPair.back();
    std::pair<int, int> value2Insert = std::make_pair(vecPair[jacobValue].first, vecPair[jacobValue].second);
    vecPair.erase(vecPair.begin() + jacobValue);
    return value2Insert;
}

//find int vector
template <class Container>
int findInVector(Container& vec, int value)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
            return i;
    }
    return vec.size();
}

//binary search insert
template <class Container>
int binarySearchInsert(Container& vec, std::pair<int, int> pairValue, std::vector<int>& jacob)
{
    int value = pairValue.first;
    int n = findInVector(vec, pairValue.second); 
    int jacobSize = jacob.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    
    while(low <= high)
    {
        jacobSize--;
        if(jacobSize < 0)
            mid = low;
        else
            mid = low + jacob[jacobSize];
        if (mid >= n)
            mid = n - 1;
        if (vec[mid] == value)
            return (mid);
        else if(vec[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return(low);
}


//insert in order 
template <class Container>
void insertInOrder(Container& vec, std::pair<int, int> value)
{
    int size = vec.size();
    std::vector<int> jacobsthal = generateJacobsthal(size);
    int pos = binarySearchInsert(vec, value, jacobsthal);
    vec.insert(vec.begin() + pos, value.first);
}

//ford johnson 
template <class Container, class C_P>
void FordJohnson(Container& vec, C_P& vecPair)
{
    std::vector<int> jacobPair;
    std::pair<int, int> value2Insert;

    int nbPair = vecPair.size();
    
    vec.clear();

    placeAllGreater(vec, vecPair);
    
    for (; nbPair > 0;)
    {
        jacobPair = generateJacobsthal(nbPair);
        value2Insert = getPairValue(jacobPair, vecPair);
        insertInOrder(vec, value2Insert);
        nbPair = vecPair.size();
    }
}

template<class Container, class C_P>
void mergeInsertSort(Container &vector, C_P &vecPair)
{
    bool isOdd = vector.size() % 2;
    std::pair<int, int> odd;

    if(isOdd)
    {
        odd.first = vector.back();
        odd.second = ODD_INT; //2147483647
        vector.pop_back();
    }
    makePairs(vector, vecPair);
    sortPairs(vecPair);
    sortVecPairs(vecPair);
    
    FordJohnson(vector, vecPair);
    if(isOdd)
        insertInOrder(vector, odd);
}

//////////////////////////////

template <class Container>
void printContainer(Container vec, bool started)
{
    (void)vec;
    if (!started)
        std::cout << "Before start: ";
}


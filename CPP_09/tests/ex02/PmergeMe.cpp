#include "PmergeMe.hpp"
 
// std::deque<int> deque;
// std::vector<int> vector;
// std::vector<std::string> strs; //Store input arguments as strings for validation

// CONSTRUCTORS ////////////////////////////////////////////

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const &src) { *this = src; }

PmergeMe& PmergeMe::operator=(PmergeMe const& src)
{
    if (this != &src)
    {
        this->_dequeData = src._dequeData;
        this->_vectorData = src._vectorData;
        this->_input = src._input;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}


// CHECKERS ////////////////////////////////////////////

//is valid int
bool isValidInt(const std::string& str)
{
    if (str.empty())
        return false;
    
    std::stringstream ss(str);
    int value;
    char remainingChar;
    if (!(ss >> value) || (ss >> remainingChar))
        return false;
    return true;
}

//parse str
bool parseStr(const std::string& input)
{
    std::stringstream ss(input);
    std::string token;
    int i = 0;//error msg 

    while (ss >> token)
    {
        i++;
        if (!isValidInt(token))
            return false;
    }
    if (i == 0)
        return false;
    return true;
}

//check dups
bool PmergeMe::hasDuplicate() const
{
    std::set<int> seen;

    for (size_t i = 0; i < _input.size(); ++i)
    {
        int value = std::atoi(_input[i].c_str());
        if (seen.find(value) != seen.end())
            return true;
        seen.insert(value);
    }
    return false;
}

//error msg 
bool errorMsg(std::string const& msg)
{
    std::cerr << msg << std::endl;
    return false;
}


// MEMBER FUNCS ////////////////////////////////////////////

//init containers
bool PmergeMe::initContainers(int ac, char *av[])
{
    if (ac < 3)
        return errorMsg("Usage: ./PmergeMe [Positive Integers <nb1> <nb2> <nb3> ...]\n");

    //check if all arg valid int
    for (int i = 1; i < ac; i++)
    {
        std::string arg(av[i]);
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(arg[j]))
            {
                std::cerr << "Error: Invalid input [" << arg << "]" << std::endl;
                return false;
            }
        }
        int num = std::atoi(av[i]);
    
        // Updated variable name
        _dequeData.push_back(num);   
        _vectorData.push_back(num);  
        _input.push_back(arg);
    }

    //check dup
    if (hasDuplicate())
    {
        std::cerr << "Error: Duplicate integer found." << std::endl;
        return false;
    }
    return true;   
}

//exec
void PmergeMe::execute(int ac, char *av[])
{
    if (!initContainers(ac, av))
        return;

    //BEFORE SORT//
    std::cout << "Before start: ";
    for (size_t i = 0; i < _vectorData.size(); ++i)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;

    // Time vector sort
    clock_t startVec = clock();
    std::sort(_vectorData.begin(), _vectorData.end());
    clock_t endVec = clock();

    // Time deque sort
    clock_t startDeq = clock();
    std::sort(_dequeData.begin(), _dequeData.end());
    clock_t endDeq = clock();


    //AFTER SORT//
    std::cout << "After start: ";
    for (size_t i = 0; i < _vectorData.size(); ++i)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;

    //timer
    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << _vectorData.size()
              << " elements with std::vector: "
              << std::fixed << std::setprecision(6) << vecTime << " sec" << std::endl;

    std::cout << "Time to process a range of " << _dequeData.size()
              << " elements with std::deque: "
              << std::fixed << std::setprecision(6) << deqTime << " sec" << std::endl;
}

//generate jacobsthal
std::vector<int>    generateJacobsthal(int nb)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    if(nb == 1)
    {
        jacobsthal.pop_back();
        return jacobsthal;
    }
    while (jacobsthal.back() < nb) 
    {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        
        if (next >= nb) 
            break;
        
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

//timer
void printTime(clock_t start, clock_t end, std::string const& containerType, int size)
{
    double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

     std::cout << "Time to process a range of " << size << " elements with std::" << containerType  << ": " 
        << std::fixed << timeTaken << " sec" << std::endl;
}

/*
𓂃𓂃𓂃𓊝 ࿐𓂃𓂃𓂃
𓇼 ⋆.˚  𓆝⋆.˚    𓇼 ⋆｡˚ 𓆞
𓆉𓆝𓇼𓆟  𖦹°‧𓆝𓆡𓆜

*/
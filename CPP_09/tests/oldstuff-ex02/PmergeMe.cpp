#include "PmergeMe.hpp"

//check input
//- check if positive int
//- check no dups
std::vector<int> checkInput(int ac, char *av[])
{
    std::vector<int> input;

    for (int i = 1; i < ac; i++)
    {
        int args = std::atoi(av[i]);
        if (args < 0)
            throw std::invalid_argument("Error : Negative numbers not allowed.");
        if (std::find(input.begin(), input.end(), args) != input.end())
            throw std::invalid_argument("Error : Duplicated numbers not allowed.");
        input.push_back(args);
    }
    return input;
}


/** Ford Johnhson template func
 * 1 check if sortable (container < 2)
 * 2 pair up & sort within each pair
 * 3 merge 
 * 
 * 
 * 
 * 
 * 
*/
//std::advance(mid, N) moves the iterator N steps forward.

// The Ford-Johnson merge-insertion sort for containers
template <typename Container>
void fordJohnsonSort(Container& container) {
    size_t n = container.size();
    if (n <= 1) return;

    // Step 1: Pair elements and divide into "larger" and "smaller" arrays
    std::vector<int> larger, smaller;

    for (size_t i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            if (container[i] > container[i + 1]) {
                larger.push_back(container[i]);
                smaller.push_back(container[i + 1]);
            } else {
                larger.push_back(container[i + 1]);
                smaller.push_back(container[i]);
            }
        } else {
            larger.push_back(container[i]);
        }
    }

    // Step 2: Recursively sort the larger elements
    std::sort(larger.begin(), larger.end()); // Using std::sort as a basic solution

    // Step 3: Inserting the smaller elements using binary insertion
    for (size_t i = 0; i < smaller.size(); ++i) {
        binaryInsert(larger, smaller[i]);
    }

    // Step 4: Copy back to original container
    container = larger;
}

// template <typename Container>
// void mergeInsertionSort(container& container)
// {
//     //if container empty or < 2 -> return
//     if (container.size() < 2)
//         return;
//     //pair & sort within each pair

    


// }

//binary insert after 
//std::lower_bound : returns an iterator pointing to the first element in the range [first, last) that is not less than value
template <typename Container, typename T>
void binaryInsert(Container& container, const T& value)
{
    //find the position to insert
    typename Container::iterator pos = std::lower_bound(container.begin(), container.end(), value);
    
    //insert the value at the found position
    container.insert(pos, value);
}


//print container
// template <typename Container>
// void printContainer(const Container& container)
// {
//     typename Container::const_iterator it;
//     for (it = container.begin(); it != container.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }


//timing funcs
//clock() : returns the number of clock ticks elapsed since the program started
// CLOCKS_PER_SEC : constant that represents the number of clock ticks per second
//1e6 is scientific notation (floating-point literal) for 1000000.0
// - clock() / CLOCKS_PER_SEC : gives the elapsed time in seconds
//double(end - start) : C style cast 
//static_cast<double>(end - start) :  C++-style cast (more explicit)
// General template for containers

// template <typename Container>
// double timer(Container& input, const std::string& containerType)
// {
//     clock_t start = 0, end = 0;
//     double duration;

//     if (containerType == "vector" || containerType == "deque") {
//         start = clock();
//         fordJohnsonSort(input); // Sort the container (same sorting function for both types)
//         end = clock();
//     }

//     duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds
//     return duration;
// }




double timer(std::vector<int>& input, const std::string& containerType)
{
    clock_t start = 0, end = 0;
    double duration;

    //vector 
    if (containerType == "vector")
    {
        // std::vector<int> vec = input;
        start = static_cast<double>(clock());
        fordJohnsonSort(input);
        end = static_cast<double>(clock());
    }
    //deque
    else if (containerType == "deque")
    {
        // std::deque<int> deq = input;
        start = static_cast<double>(clock());
        fordJohnsonSort(input);
        end = static_cast<double>(clock());
    }
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds
    return (duration);
}

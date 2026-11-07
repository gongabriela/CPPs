#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

const char* PmergeMe::ErrorException::what() const throw()
{
    return "Error";
}

long long PmergeMe::getTimeMicroseconds() const
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

size_t PmergeMe::getJacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t current = 0;
    
    for (size_t i = 2; i <= n; ++i)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

void PmergeMe::sortVector(std::vector<int>& container)
{
    if (container.size() <= 1)
        return;

    bool hasOdd = (container.size() % 2 != 0);
    int oddElement = 0;
    if (hasOdd)
    {
        oddElement = container.back();
        container.pop_back();
    }

    std::vector< std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2)
    {
        if (container[i] > container[i + 1])
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        else
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
    }

    std::vector<int> S;
    for (size_t i = 0; i < pairs.size(); ++i)
        S.push_back(pairs[i].first);

    sortVector(S);

    std::vector<int> X;
    std::vector<bool> used(pairs.size(), false);
    for (size_t i = 0; i < S.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].first == S[i])
            {
                X.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    if (!X.empty())
        S.insert(S.begin(), X[0]);

    std::vector<size_t> j_seq;
    size_t j_idx = 3;
    while (true)
    {
        size_t val = getJacobsthal(j_idx);
        j_seq.push_back(val);
        if (val > X.size())
            break;
        j_idx++;
    }

    size_t prev_j = 1;
    for (size_t k = 0; k < j_seq.size(); ++k)
    {
        size_t curr_j = j_seq[k];
        if (curr_j > X.size())
            curr_j = X.size();

        // Inserir de tras para a frente ate ao salto anterior
        for (size_t i = curr_j; i > prev_j; --i)
        {
            int loser = X[i - 1];
            std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), loser);
            S.insert(pos, loser);
        }
        prev_j = curr_j;
    }

    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), oddElement);
        S.insert(pos, oddElement);
    }

    container = S;
}

void PmergeMe::sortDeque(std::deque<int>& container)
{
    if (container.size() <= 1)
        return;

    bool hasOdd = (container.size() % 2 != 0);
    int oddElement = 0;
    if (hasOdd)
    {
        oddElement = container.back();
        container.pop_back();
    }

    std::deque< std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2)
    {
        if (container[i] > container[i + 1])
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        else
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
    }

    std::deque<int> S;
    for (size_t i = 0; i < pairs.size(); ++i)
        S.push_back(pairs[i].first);

    sortDeque(S);

    std::deque<int> X;
    std::deque<bool> used(pairs.size(), false);
    for (size_t i = 0; i < S.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].first == S[i])
            {
                X.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    if (!X.empty())
        S.insert(S.begin(), X[0]);

    std::deque<size_t> j_seq;
    size_t j_idx = 3;
    while (true)
    {
        size_t val = getJacobsthal(j_idx);
        j_seq.push_back(val);
        if (val > X.size())
            break;
        j_idx++;
    }

    size_t prev_j = 1;
    for (size_t k = 0; k < j_seq.size(); ++k)
    {
        size_t curr_j = j_seq[k];
        if (curr_j > X.size())
            curr_j = X.size();

        for (size_t i = curr_j; i > prev_j; --i)
        {
            int loser = X[i - 1];
            std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), loser);
            S.insert(pos, loser);
        }
        prev_j = curr_j;
    }
    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), oddElement);
        S.insert(pos, oddElement);
    }

    container = S;
}

void PmergeMe::process(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        std::string token;
        
        while (ss >> token)
        {
            char *end;
            long val = std::strtol(token.c_str(), &end, 10);

            if (*end != '\0' || val < 0 || val > INT_MAX)
                throw ErrorException();
                
            _vector.push_back(static_cast<int>(val));
            _deque.push_back(static_cast<int>(val));
        }
    }

    if (_vector.empty())
        throw ErrorException();

    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << (i + 1 == _vector.size() ? "" : " ");
    std::cout << "\n";

    long long startVec = getTimeMicroseconds();
    sortVector(_vector);
    long long endVec = getTimeMicroseconds();

    long long startDeq = getTimeMicroseconds();
    sortDeque(_deque);
    long long endDeq = getTimeMicroseconds();

    std::cout << "After:  ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << (i + 1 == _vector.size() ? "" : " ");
    std::cout << "\n";

    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << (endVec - startVec) << " us\n";
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << (endDeq - startDeq) << " us\n";
}

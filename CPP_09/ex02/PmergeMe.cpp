#include "PmergeMe.hpp"

/**
 * @brief Default constructor: creates the object with empty containers.
 */
PmergeMe::PmergeMe() {}

/**
 * @brief Copy constructor.
 *
 * @param other Object to copy (both containers).
 */
PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

/**
 * @brief Copy assignment operator.
 *
 * @param other Object to copy (both containers).
 * @return A reference to this object.
 */
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

/**
 * @brief Destructor.
 */
PmergeMe::~PmergeMe() {}

/**
 * @brief Returns the error message.
 *
 * @return Always `"Error"`, as required by the subject.
 */
const char* PmergeMe::ErrorException::what() const throw()
{
    return "Error";
}

/**
 * @brief Returns the current time in microseconds.
 *
 * Uses `gettimeofday`; the time spent by each container is measured as the
 * difference between two calls.
 *
 * @return Microseconds since the Epoch.
 */
long long PmergeMe::getTimeMicroseconds() const
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

/**
 * @brief Computes the n-th Jacobsthal number.
 *
 * The sequence is defined by J(0) = 0, J(1) = 1 and J(n) = J(n-1) + 2 * J(n-2):
 * 0, 1, 1, 3, 5, 11, 21, 43, ... From J(3) onwards, these numbers delimit the
 * insertion groups of Ford-Johnson.
 *
 * @param n Index in the sequence.
 * @return The value of J(n).
 */
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

namespace
{
    /**
     * @brief Index comparator for a `std::vector`.
     *
     * The algorithm sorts indices (positions in the original sequence) instead
     * of values; this comparator compares the values stored at those positions.
     * It is used by `std::lower_bound` in the binary search.
     */
    struct VecIdxLess
    {
        /** @brief Original sequence, where the indices are looked up. */
        const std::vector<int>& values;

        /**
         * @brief Creates the comparator for a sequence.
         * @param v Original sequence.
         */
        VecIdxLess(const std::vector<int>& v) : values(v) {}

        /**
         * @brief Compares the values at two positions.
         * @param a First index.
         * @param b Second index.
         * @return `true` if `values[a] < values[b]`.
         */
        bool operator()(size_t a, size_t b) const { return values[a] < values[b]; }
    };

    /**
     * @brief Index comparator for a `std::deque`.
     *
     * Same as VecIdxLess, for the `std::deque` implementation.
     */
    struct DeqIdxLess
    {
        /** @brief Original sequence, where the indices are looked up. */
        const std::deque<int>& values;

        /**
         * @brief Creates the comparator for a sequence.
         * @param v Original sequence.
         */
        DeqIdxLess(const std::deque<int>& v) : values(v) {}

        /**
         * @brief Compares the values at two positions.
         * @param a First index.
         * @param b Second index.
         * @return `true` if `values[a] < values[b]`.
         */
        bool operator()(size_t a, size_t b) const { return values[a] < values[b]; }
    };
}

/**
 * @brief Sorts indices with the Ford-Johnson algorithm (`std::vector` version).
 *
 * The values never move: what gets sorted is the list of indices, and every
 * comparison is between `values[a]` and `values[b]`. Since indices are unique,
 * each element is identified unambiguously, even when values are repeated.
 *
 * Steps:
 * 1. If the number of indices is odd, the last one is set aside, unpaired.
 * 2. Indices are paired and compared (one comparison per pair). The larger one
 *    of each pair goes to `winners`, and `partner[winner]` stores the smaller.
 * 3. The winners are sorted recursively.
 * 4. The losers are placed in `losers`, in the order of the now sorted winners,
 *    read from `partner` without any comparison.
 * 5. The main chain starts with the first loser, which is less than or equal
 *    to the smallest winner and can therefore go in front with no comparison,
 *    followed by the winners. `pos[k]` holds the current position, in the
 *    chain, of the winner paired with `losers[k]`. The odd element is appended
 *    to `losers`, with no winner.
 * 6. The remaining losers are inserted in groups delimited by the Jacobsthal
 *    numbers (3 2, 5 4, 11 10 ... 6, ...), each group from the highest index to
 *    the lowest. Since every loser is less than or equal to its winner, the
 *    binary search only goes up to that winner's position (or to the end, for
 *    the odd element). This order ensures that every search runs over at most
 *    2^k - 1 elements, which gives the minimum number of comparisons. After each
 *    insertion at position `p`, the winners at position `p` or later move one
 *    step forward; since `pos` is increasing, it is enough to walk it from the
 *    end towards the start.
 *
 * @param values Original sequence (read only).
 * @param idx    Indices to sort; on return they are in increasing value order.
 */
void PmergeMe::sortVectorIdx(const std::vector<int>& values, std::vector<size_t>& idx)
{
    if (idx.size() <= 1)
        return;

    bool   hasOdd = (idx.size() % 2 != 0);
    size_t oddIdx = 0;
    if (hasOdd)
    {
        oddIdx = idx.back();
        idx.pop_back();
    }

    std::vector<size_t> winners;
    std::vector<size_t> partner(values.size());
    for (size_t i = 0; i < idx.size(); i += 2)
    {
        size_t a = idx[i];
        size_t b = idx[i + 1];
        if (values[a] > values[b])
        {
            winners.push_back(a);
            partner[a] = b;
        }
        else
        {
            winners.push_back(b);
            partner[b] = a;
        }
    }

    sortVectorIdx(values, winners);

    std::vector<size_t> losers;
    for (size_t i = 0; i < winners.size(); ++i)
        losers.push_back(partner[winners[i]]);

    std::vector<size_t> chain;
    chain.push_back(losers[0]);
    chain.insert(chain.end(), winners.begin(), winners.end());
    std::vector<size_t> pos(winners.size());
    for (size_t k = 0; k < pos.size(); ++k)
        pos[k] = k + 1;

    if (hasOdd)
        losers.push_back(oddIdx);

    VecIdxLess less(values);
    size_t prev_j = 1;
    size_t j_idx = 3;
    while (prev_j < losers.size())
    {
        size_t curr_j = getJacobsthal(j_idx);
        if (curr_j > losers.size())
            curr_j = losers.size();

        for (size_t i = curr_j; i > prev_j; --i)
        {
            size_t li = i - 1;
            std::vector<size_t>::iterator limit =
                (li < pos.size()) ? chain.begin() + pos[li] : chain.end();
            std::vector<size_t>::iterator it =
                std::lower_bound(chain.begin(), limit, losers[li], less);
            size_t p = it - chain.begin();
            chain.insert(it, losers[li]);
            for (size_t j = pos.size(); j > 0 && pos[j - 1] >= p; --j)
                pos[j - 1]++;
        }
        prev_j = curr_j;
        ++j_idx;
    }

    idx = chain;
}

/**
 * @brief Sorts a `std::vector` with the Ford-Johnson algorithm.
 *
 * Builds the list of indices 0..n-1, sorts it with sortVectorIdx() and rebuilds
 * the container with the values in the new order.
 *
 * @param container Container to sort; on return it is in increasing order.
 */
void PmergeMe::sortVector(std::vector<int>& container)
{
    std::vector<size_t> idx(container.size());
    for (size_t i = 0; i < idx.size(); ++i)
        idx[i] = i;

    sortVectorIdx(container, idx);

    std::vector<int> sorted(container.size());
    for (size_t i = 0; i < idx.size(); ++i)
        sorted[i] = container[idx[i]];
    container = sorted;
}

/**
 * @brief Sorts indices with the Ford-Johnson algorithm (`std::deque` version).
 *
 * Same algorithm as sortVectorIdx(), implemented separately with `std::deque`,
 * as the subject recommends. See sortVectorIdx() for a description of the
 * steps.
 *
 * @param values Original sequence (read only).
 * @param idx    Indices to sort; on return they are in increasing value order.
 */
void PmergeMe::sortDequeIdx(const std::deque<int>& values, std::deque<size_t>& idx)
{
    if (idx.size() <= 1)
        return;

    bool   hasOdd = (idx.size() % 2 != 0);
    size_t oddIdx = 0;
    if (hasOdd)
    {
        oddIdx = idx.back();
        idx.pop_back();
    }

    std::deque<size_t> winners;
    std::deque<size_t> partner(values.size());
    for (size_t i = 0; i < idx.size(); i += 2)
    {
        size_t a = idx[i];
        size_t b = idx[i + 1];
        if (values[a] > values[b])
        {
            winners.push_back(a);
            partner[a] = b;
        }
        else
        {
            winners.push_back(b);
            partner[b] = a;
        }
    }

    sortDequeIdx(values, winners);

    std::deque<size_t> losers;
    for (size_t i = 0; i < winners.size(); ++i)
        losers.push_back(partner[winners[i]]);

    std::deque<size_t> chain(winners);
    chain.push_front(losers[0]);
    std::deque<size_t> pos(winners.size());
    for (size_t k = 0; k < pos.size(); ++k)
        pos[k] = k + 1;

    if (hasOdd)
        losers.push_back(oddIdx);

    DeqIdxLess less(values);
    size_t prev_j = 1;
    size_t j_idx = 3;
    while (prev_j < losers.size())
    {
        size_t curr_j = getJacobsthal(j_idx);
        if (curr_j > losers.size())
            curr_j = losers.size();

        for (size_t i = curr_j; i > prev_j; --i)
        {
            size_t li = i - 1;
            std::deque<size_t>::iterator limit =
                (li < pos.size()) ? chain.begin() + pos[li] : chain.end();
            std::deque<size_t>::iterator it =
                std::lower_bound(chain.begin(), limit, losers[li], less);
            size_t p = it - chain.begin();
            chain.insert(it, losers[li]);
            for (size_t j = pos.size(); j > 0 && pos[j - 1] >= p; --j)
                pos[j - 1]++;
        }
        prev_j = curr_j;
        ++j_idx;
    }

    idx = chain;
}

/**
 * @brief Sorts a `std::deque` with the Ford-Johnson algorithm.
 *
 * Builds the list of indices 0..n-1, sorts it with sortDequeIdx() and rebuilds
 * the container with the values in the new order.
 *
 * @param container Container to sort; on return it is in increasing order.
 */
void PmergeMe::sortDeque(std::deque<int>& container)
{
    std::deque<size_t> idx(container.size());
    for (size_t i = 0; i < idx.size(); ++i)
        idx[i] = i;

    sortDequeIdx(container, idx);

    std::deque<int> sorted(container.size());
    for (size_t i = 0; i < idx.size(); ++i)
        sorted[i] = container[idx[i]];
    container = sorted;
}

/**
 * @brief Converts a token to a positive integer.
 *
 * The token must be a complete integer (no extra characters), between 0 and
 * `INT_MAX`.
 *
 * @param token Text to convert.
 * @param out   Receives the converted value, if it is valid.
 * @return `true` if the token is valid, `false` otherwise.
 */
bool PmergeMe::parseNumber(const std::string& token, int& out) const
{
    char *end;
    long val = std::strtol(token.c_str(), &end, 10);

    if (*end != '\0' || val < 0 || val > INT_MAX)
        return false;
    out = static_cast<int>(val);
    return true;
}

/**
 * @brief Validates the whole input without storing anything.
 *
 * Each argument may hold one or more numbers separated by spaces. Validation
 * happens before anything is printed, so that an error prints only `Error`.
 *
 * @param argc Number of program arguments.
 * @param argv Program arguments.
 * @throws ErrorException If any token is invalid or there are no numbers.
 */
void PmergeMe::validateInput(int argc, char** argv) const
{
    size_t count = 0;

    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        std::string token;
        int value;

        while (ss >> token)
        {
            if (!parseNumber(token, value))
                throw ErrorException();
            ++count;
        }
    }
    if (count == 0)
        throw ErrorException();
}

/**
 * @brief Reads the numbers from the arguments into `_vector`.
 *
 * Part of the time measured for `std::vector` (the "data management" required
 * by the subject). Assumes the input was already validated by validateInput().
 *
 * @param argc Number of program arguments.
 * @param argv Program arguments.
 */
void PmergeMe::fillVector(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        std::string token;
        int value;

        while (ss >> token)
            if (parseNumber(token, value))
                _vector.push_back(value);
    }
}

/**
 * @brief Reads the numbers from the arguments into `_deque`.
 *
 * Part of the time measured for `std::deque`. Assumes the input was already
 * validated by validateInput().
 *
 * @param argc Number of program arguments.
 * @param argv Program arguments.
 */
void PmergeMe::fillDeque(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        std::string token;
        int value;

        while (ss >> token)
            if (parseNumber(token, value))
                _deque.push_back(value);
    }
}

/**
 * @brief Validates the input, sorts it in both containers and prints the result.
 *
 * 1. Validates the whole input (an error prints only `Error`).
 * 2. Prints the original sequence (`Before:`), read directly from the arguments.
 * 3. Times `std::vector`: filling the container + sorting.
 * 4. Times `std::deque`: the same work, also starting from the input.
 * 5. Prints the sorted sequence (`After:`) and both timings, in microseconds.
 *
 * @param argc Number of program arguments.
 * @param argv Program arguments (the numbers to sort).
 * @throws ErrorException If the input is invalid.
 */
void PmergeMe::process(int argc, char** argv)
{
    validateInput(argc, argv);

    std::cout << "Before: ";
    bool first = true;
    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        std::string token;
        int value;

        while (ss >> token)
        {
            if (!parseNumber(token, value))
                continue;
            std::cout << (first ? "" : " ") << value;
            first = false;
        }
    }
    std::cout << "\n";

    long long startVec = getTimeMicroseconds();
    fillVector(argc, argv);
    sortVector(_vector);
    long long endVec = getTimeMicroseconds();

    long long startDeq = getTimeMicroseconds();
    fillDeque(argc, argv);
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

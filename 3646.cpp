using ll = long long;

// Count total digits, how many odd counts, and which odd digit appears
vector<int> analyzeMask(ll mask) {
    int totalDigits = 0;
    int oddCount = 0;
    int oddDigit = -1;

    for (int bit = 8; bit >= 0; --bit) {
        if (mask & (1 << bit)) {
            int digit = bit + 1;
            totalDigits += digit;
            if (digit % 2 == 1) {
                oddCount++;
                oddDigit = digit;
            }
        }
    }
    return { totalDigits, oddCount, oddDigit };
}

// Construct the left half of a palindrome string
string buildHalfString(int mask) {
    string result = "";
    for (int bit = 0; bit < 9; ++bit) {
        if ((mask >> bit) & 1) {
            int digit = bit + 1;
            result.append(digit / 2, char('0' + digit));
        }
    }
    return result;
}

// Precompute all valid palindromes
const vector<ll> generatePalindromes() {
    vector<ll> palindromes;

    for (ll mask = 1; mask < (1 << 9); ++mask) {
        auto stats = analyzeMask(mask);
        int totalDigits = stats[0];
        int oddCount = stats[1];
        int oddDigit = stats[2];

        // Valid palindrome condition:
        // - at most one odd digit
        // - total length ≤ 16
        if (oddCount > 1 || totalDigits > 16) continue;

        string half = buildHalfString(mask);
        sort(half.begin(), half.end());

        // Generate all permutations of the half
        do {
            string pal = half;
            if (oddDigit != -1) {
                pal += char('0' + oddDigit);
            }
            pal.append(half.rbegin(), half.rend());
            palindromes.push_back(stoll(pal));
        } while (next_permutation(half.begin(), half.end()));
    }

    // Remove duplicates and sort
    sort(palindromes.begin(), palindromes.end());
    palindromes.erase(unique(palindromes.begin(), palindromes.end()), palindromes.end());

    return palindromes;
}

// Precompute once
const vector<ll> allPalindromes = generatePalindromes();

// Solution class for queries
class Solution {
public:
    long long specialPalindrome(long long n) {
        return *upper_bound(allPalindromes.begin(), allPalindromes.end(), n);
    }
};

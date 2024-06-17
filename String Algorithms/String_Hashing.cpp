class HashedString
{
private:
    static const int M1 = 1e9 + 9;
    static const int B1 = 9973;
    static const int M2 = 1e9 + 7;
    static const int B2 = 10007;

    static vector<int> pow1, pow2;

    vector<int> p_hash1, p_hash2;

public:
    HashedString(const string &s) : p_hash1(s.size() + 1), p_hash2(s.size() + 1)
    {
        while (pow1.size() <= s.size())
        {
            pow1.push_back((pow1.back() * B1) % M1);
        }
        while (pow2.size() <= s.size())
        {
            pow2.push_back((pow2.back() * B2) % M2);
        }

        p_hash1[0] = 0;
        p_hash2[0] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            p_hash1[i + 1] = ((p_hash1[i] * B1) % M1 + s[i]) % M1;
            p_hash2[i + 1] = ((p_hash2[i] * B2) % M2 + s[i]) % M2;
        }
    }

    pair<int, int> get_hash(int start, int end)
    {
        if (start > end)
            return {0, 0};
        int raw_val1 = (p_hash1[end + 1] - (p_hash1[start] * pow1[end - start + 1]) % M1 + M1) % M1;
        int raw_val2 = (p_hash2[end + 1] - (p_hash2[start] * pow2[end - start + 1]) % M2 + M2) % M2;
        return {raw_val1, raw_val2};
    }

    static pair<int, int> concatenate_hashes(const vector<pair<pair<int, int>, int>> &hashes)
    {
        int combined_hash1 = 0;
        int combined_hash2 = 0;
        int cumulative_length = 0;

        for (size_t i = 0; i < hashes.size(); ++i)
        {
            auto [hash, length] = hashes[i];
            auto [hash1, hash2] = hash;

            combined_hash1 = (combined_hash1 * pow1[length] % M1 + hash1) % M1;
            combined_hash2 = (combined_hash2 * pow2[length] % M2 + hash2) % M2;

            cumulative_length += length;

            while (pow1.size() <= cumulative_length)
            {
                pow1.push_back((pow1.back() * B1) % M1);
            }
            while (pow2.size() <= cumulative_length)
            {
                pow2.push_back((pow2.back() * B2) % M2);
            }
        }
        return {combined_hash1, combined_hash2};
    }
};

vector<int> HashedString::pow1 = {1};
vector<int> HashedString::pow2 = {1};

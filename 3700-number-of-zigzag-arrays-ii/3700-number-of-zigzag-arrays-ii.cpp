#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

using matrix = vector<int>;

int m;

static inline matrix operator*(const matrix& A, const matrix& B) {
    matrix C(m * m, 0);

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            if (A[i * m + k] == 0)
                continue;

            for (int j = 0; j < m; j++) {
                C[i * m + j] =
                    (C[i * m + j] +
                     1LL * A[i * m + k] * B[k * m + j]) % mod;
            }
        }
    }

    return C;
}

static matrix I() {
    matrix ans(m * m, 0);

    for (int i = 0; i < m; i++)
        ans[i * m + i] = 1;

    return ans;
}

static matrix pow(const matrix& M, unsigned exp) {
    if (exp == 0)
        return I();

    int bMax = 31 - __builtin_clz(exp);

    matrix ans = M;

    for (int i = bMax - 1; i >= 0; i--) {
        ans = ans * ans;

        if ((exp >> i) & 1)
            ans = ans * M;
    }

    return ans;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {

        m = r - l + 1;

        // MUST be m*m, not m*n
        matrix U(m * m, 0);
        matrix L(m * m, 0);

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                U[i * m + j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                L[i * m + j] = 1;
            }
        }

        n--;

        int n0 = n >> 1;

        matrix UL = U * L;

        matrix P = pow(UL, n0);

        if (n & 1)
            P = L * P;

        return 2LL *
               reduce(P.begin(), P.end(), 0LL) %
               mod;
    }
};
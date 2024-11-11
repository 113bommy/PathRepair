import io
import os

from collections import Counter, defaultdict, deque


MOD = 998244353

MAX_N = 3 * 10 ** 5 + 10


def modInverse(a, p):
    # Fermat's little theorem, a**(p-1) = 1 mod p
    # assert a % p != 0
    return pow(a, p - 2, p)


# Precompute all factorials: i!
fact = [1]
for i in range(1, MAX_N + 1):
    fact.append((fact[-1] * i) % MOD)

# Precompute all inverse factorials: 1 / i!
invFact = [0] * (MAX_N + 1)
invFact[MAX_N] = modInverse(fact[MAX_N], MOD)
for i in range(MAX_N - 1, -1, -1):
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD
    # assert fact[i] * invFact[i] % MOD == 1


def nCr(n, r):  # mod'd
    if n < r:
        return 0
    return (fact[n] * invFact[r] * invFact[n - r]) % MOD


def f(arr):
    consec = []
    for c in arr:
        if not consec or consec[-1][-1] != c - 1:
            consec.append([c])
        else:
            consec[-1].append(c)
    return consec


def makeConsec(rows):

    for r in rows:
        rows[r].sort()
        consec = f(rows[r])
        consec = list(map(len, consec))
        rows[r] = consec

    return rows


def group(cells):

    rows = defaultdict(list)
    cols = defaultdict(list)
    for r, c in cells:
        rows[r].append(c)
        cols[c].append(r)
    return makeConsec(rows), makeConsec(cols)


def solve1(R, C, grid):
    assert len(grid) == R
    assert len(grid[0]) == C

    whites = [(r, c) for r in range(R) for c in range(C) if grid[r][c] == 0]

    score = 0
    for mask in range(1 << len(whites)):
        reds = []
        blues = []

        for i, (r, c) in enumerate(whites):
            if (1 << i) & mask:
                reds.append((r, c))
            else:
                blues.append((r, c))

        redUsable, _ = group(reds)
        _, blueUsable = group(blues)
        score += sum(l // 2 for r, cols in redUsable.items() for l in cols)
        score += sum(l // 2 for c, rows in blueUsable.items() for l in rows)
        score %= MOD

    return score

inv9 = modInverse(9, MOD)

def solve(R, C, grid):
    assert len(grid) == R
    assert len(grid[0]) == C

    whites = [(r, c) for r in range(R) for c in range(C) if grid[r][c] == 0]

    ans = 0
    for grouping in group(whites):
        for k in grouping:
            for l in grouping[k]:

                otherMasks = pow(2, len(whites) - l, MOD)
                if l >= 2:
                    l -= 1
                        
                    ways = ((3 * l + 1) * pow(2, l, MOD) - pow(-1, (l % 2))) * inv9
                    ans += otherMasks * ways
                    ans %= MOD
    return ans

if True:
    R = 1
    for C in range(1, 10):
        print(C, solve1(R, C , [[0 for i in range(C)]]))

if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    TC = 1  # int(input())
    for tc in range(1, TC + 1):
        N, M = [int(x) for x in input().split()]
        grid = [[int(c == "*") for c in input().decode().rstrip()] for i in range(N)]
        ans = solve(N, M, grid)
        print(ans)

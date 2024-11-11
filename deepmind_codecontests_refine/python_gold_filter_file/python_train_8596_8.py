import math
from collections import defaultdict

def input_ints():
    return list(map(int, input().split()))

def solve():
    n, k = input_ints()
    a = input_ints()
    b = input_ints()
    x = [(a[i] - b[i], b[i]) for i in range(n)]
    x = sorted(x)
    ans = 0
    for i, p in enumerate(x):
        if i < k or p[0] <= 0:
            ans += p[0] + p[1]
        else:
            ans += p[1]
    print(ans)

if __name__ == '__main__':
    solve()

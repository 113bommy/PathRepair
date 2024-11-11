from collections import Counter

N = int(input())
S = input()

left, right = S[:N], S[N:][::-1]
a, b = Counter(), Counter()

for i in range(2 ** N):
    t = "".join(left[j] if (i >> j) & 1 else "" for j in range(N))
    u = "".join(right[j] if (i >> j) & 1 else "" for j in range(N))
    v = "".join("" if (i >> j) & 1 else left[j] for j in range(N))
    w = "".join("" if (i >> j) & 1 else right[j] for j in range(N))
    a[t, v] += 1
    b[u, w] += 1

print((sum(a[t] * b[t] for t in a.keys())))
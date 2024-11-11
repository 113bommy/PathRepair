from collections import Counter

N = int(input())
S = input()

left, right = S[:N], S[N:][::-1]
a, b = Counter(), Counter()

for i in range(2 ** N):
    t = u = v = w = ""
    for j in range(N):
        if (i >> j) & 1:
            t += left[j]
            u += right[j]
        else:
            v += left[j]
            w += right[j]
    a[t, v] += 1
    b[u, w] += 1

print(sum(a[t] * b[t] for t in a.keys()))
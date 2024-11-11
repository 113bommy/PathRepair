from collections import Counter
input()
s = 0
c = Counter(map(int, input().split()))
for i in c:
    s += sum(c[i] * (c[i] - 1) // 2 if j == 2 * i else c[i] * c[j - i] for j in [2 ** k for k in range(17)])
    c[i] = 0
print(s)
from collections import Counter
n, *A = map(int, open(0).read().split())
A.sort()
c, s = Counter(A), set()
M = max(A) + 1
ans = 0
for a in A:
    if a in s:
        continue
    ans += c[a] == 1
    for i in range(a * a, M, a):
        s.add(i)
print(ans)
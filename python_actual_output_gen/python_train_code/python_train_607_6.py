
n, m = map(int, input().split())
k = min(m, n) + 1
print(k)
for i in range(k):
     print(i, k - i)

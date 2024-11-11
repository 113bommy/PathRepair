n, m, k = map(int, input().split())
p = list(map(int, input().split()))
s = list(map(int, input().split()))
c = list(map(int, input().split()))

schools = [[] for i in range(m)]
for i in range(n):
    schools[s[i] - 1].append(p[i])

for i in range(m):
    schools[i].sort(reverse=True)

l = 0
for i in c:
    if schools[s[i - 1] - 1][0] != i and m + l <= n:
        l += 1

print(l)
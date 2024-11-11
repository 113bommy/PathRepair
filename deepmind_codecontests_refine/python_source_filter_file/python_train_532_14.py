from collections import defaultdict
n, m, k = map(int, input().split())
p = list(map(int, input().split()))
s = list(map(int, input().split()))
id = list(map(int, input().split()))
d = defaultdict(int)
for i in range(n):
    d[s[i]] = max(d[s[i]], p[i])

num = 0
for i in id:
    if d[s[i - 1]] >= p[i - 1]:
        num += 1

print(num)


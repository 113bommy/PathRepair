# Sereja and Suffixes

from collections import Counter

n, m = map(int, input().split())
array = list(map(int, input().split()))
queries = []
for i in range(m):
    l = int(input())
    queries.append(l)
s_queries = set(sorted(queries))

j = 0
ans = {}
c = Counter(array)

for q in s_queries:
    while j < q - 1:
        c[array[j]] -= 1
        if c[array[j]] == 0: del c[array[j]]
        j += 1
    ans[q] = len(c)

for q in queries:
    print(ans[q])

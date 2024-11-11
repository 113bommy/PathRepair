from itertools import product
from itertools import permutations
n = int(input())
s = []
for i in range(n):
    s.append(list(input().split()))


ans = []
for x in product(*s):
    for z in range(n):
        for y in list(permutations(x, z + 1)):
            ans.append(int("".join(y)))

ans.append(0)
a = list(set(ans))

a.sort()
last = 0
for i in range(len(a)):
    c = a[i]
    if last == c - 1:
        last = c
    else:
        break
print(last)


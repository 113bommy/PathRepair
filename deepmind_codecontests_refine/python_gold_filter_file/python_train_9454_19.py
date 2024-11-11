# https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d

from itertools import combinations

n = int(input())
k = -1
for i in range(10**3):
    if i*i - i - 2 * n == 0:
        k = i

if k == -1:
    print('No')
    exit()

# print('Yes')
# print(k)

num = 0
V = [[] for _ in range(k)]
for cmb in combinations(range(k), r=2):
    num += 1
    a, b = cmb
    V[a].append(num)
    V[b].append(num)
print('Yes')
print(k)
for v in V:
    print(len(v), end=" ")
    print(*v)

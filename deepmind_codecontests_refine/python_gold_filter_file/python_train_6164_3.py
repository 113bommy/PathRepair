def union(a, b):
    a = find(a)
    b = find(b)
    lt[b] = a


def find(x):
    while (lt[x] != x):
        x = (lt[x])
    return x


import sys
input = sys.stdin.readline
n = int(input())
lt = dict()
for i in range(n):
    s = input().rstrip()
    for j in s:
        if (j not in lt):
            lt[j] = j
        union(s[0], j)
        #print(lt)
# print(lt)
ans = set()
for i in lt:
    ans.add(find(i))
print(len(ans))
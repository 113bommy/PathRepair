n = int(input())
s = list(input())
s = [ord(i)-97 for i in s]

dic = {}
for i in range(26):
    dic[i] = []

for i in range(n):
    dic[s[i]].append(i)

for i in range(26):
    dic[i].append(float('inf'))

from bisect import bisect_left
q = int(input())
for i in range(q):
    x, y, z = input().split()
    if x == '1':
        y, z = int(y) - 1, ord(z) - 97
        p = bisect_left(dic[s[y]], y)
        dic[s[y]].pop(p)
        dic[z].insert(bisect_left(dic[z], y), y)
        s[y] = z
    else:
        res = 0
        y, z = int(y) - 1, int(z) - 1
        for i in range(26):
            p = dic[i][bisect_left(dic[i], y)]
            if p <= z:
                res += 1
        print(res)
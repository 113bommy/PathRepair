from math import ceil
x = int(input())
s = sorted(list(map(int, input().split())))
res = []
a = 0
b = x-1
while a < b:
    res.append(s[b])
    res.append(s[a])
    a += 1
    b -= 1
if a == b:
    res.append(s[a])
print(ceil(x/2)-1)
print(*res)

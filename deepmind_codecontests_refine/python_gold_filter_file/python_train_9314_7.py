from collections import defaultdict

n, a, b = map(int, input().split())

same_x = 0
same_y = 0

d1 = defaultdict((lambda : 0))
d2 = defaultdict((lambda : 0))
c1 = []
c2 = []
c3 = []
c4 = []

for _ in range(n):
    x, y = map(int, input().split())
    if x == a:
        same_x = 1
    elif y == b: 
        same_y = 1
    else:
        if x > a and y > b:
            c1.append((x, y))
        elif x < a and y > b:
            c2.append((x, y))
        elif x < a and y < b:
            c3.append((x, y))
        else:
            c4.append((x,y))

cnt = same_x + same_y

for x, y in c1:
    d1[abs(x - a) / abs(y - b)] = 1

for x, y in c3:
    d1[abs(x - a) / abs(y - b)] = 1

for k in d1.keys():
    cnt += d1[k]

for x, y in c2:
    d2[abs(x - a) / abs(y - b)] = 1

for x, y in c4:
    d2[abs(x - a) / abs(y - b)] = 1

for k in d2.keys():
    cnt += d2[k]

print(cnt)
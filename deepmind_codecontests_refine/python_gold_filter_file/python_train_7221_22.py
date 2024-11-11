def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(mi())
a = []
for i in range(5):
    a.append(li())
c = 0
d = 0
for i in range(5):
    for j in range(5):
        if a[i][j] == 1:
            c = i
            d = j
res = abs((2-c))+abs((2-d))
print(res)
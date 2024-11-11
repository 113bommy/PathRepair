def cal(x1, y1, x2, y2):
    c = abs(x2-x1) + abs(y2 -y1) 
    if ((y1 != y2) and (x1 != x2)):
        c += 2
    return int(c)
 
 
t = int(input())
c = []
for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    r = cal(x1, y1, x2, y2)
    c.append(r)
for i in c:
    print(i)
#sys.stdin = open('inC', 'r')
#n = int(input())
n,q = map(int, input().split())
a = [int(x) for x in input().split()]
mx = max(a)
d = {}
i = 0
while a[i] != mx:
    x,y = a[i],a[i+1]
    a.append(min(x,y))
    a[i+1] = max(x,y)
    i += 1
    d[i] = (x,y)
la = len(a)
for qi in range(q):
    mj = int(input())
    if mj <= i:
        print(d[mj][0], d[mj][1])
    else:
        dif = mj - i
        print(mx, a[i + (dif%(n-1))])

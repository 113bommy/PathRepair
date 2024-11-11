
n,m = [int(x) for x in input().split()]

L = []
for i in range(0,n):
    L.append(input())
    
hmin = n
hmax = -1
wmin = m
wmax = -1

for i in range(0,n):
    for j in range(0,m):
        if L[i][j] == '*':
            if j < wmin:
                wmin = j
            if j > wmax:
                wmax = j
            if i > hmax:
                hmax = i
            if i < hmin:
                hmin = i

for i in range(hmin,hmax+1):
    for j in range(wmin,wmax):
        print(L[i][j],end = '' )
    print(L[i][hmax])


h,w,d = map(int,input().split())
a = [list(map(int,input().split())) for i in range(h)]
r = [None for i in range(h*w+1)]
for i in range(h):
    for j in range(w):
        r[a[i][j]] = (i,j)
#print(r)

c = [0 for i in range(h*w+1)]
for i in range(d+1,h*w+1):
    c[i] = c[i-d] + abs(r[i][0]-r[i-d][0]) + abs(r[i][1]-r[i-d][1])
#print(c)
q = int(input())
for _ in range(q):
    x,y = map(int,input().split())
    print(c[y]-c[x])

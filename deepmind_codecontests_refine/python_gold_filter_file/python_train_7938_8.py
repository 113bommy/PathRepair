n,m,x,y = map(int,input().split())
print(x,y)
for i in range(1,y):
    print(x,i)
for i in range(y+1,m+1):
    print(x,i)
vis = [False] * n
vis[x-1] = True
swap = 0
for i in range(0,n):
    if vis[i]:
        swap = 1
        continue
    if not swap:
        if i % 2 == 0:
            for j in range(m,0,-1):
                print(i+1,j)
        else:
            for j in range(1,m+1):
                print(i+1,j)
    else:
        if i % 2 == 1:
            for j in range(m,0,-1):
                print(i+1,j)
        else:
            for j in range(1,m+1):
                print(i+1,j)
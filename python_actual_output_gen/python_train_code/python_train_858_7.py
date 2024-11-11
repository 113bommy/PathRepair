n,m,k = [int(x) for x in input().split()]
l = []
for i in range(n):
    if (i%2==0):
        for j in range(m):
            l.append(i+1)
            l.append(j+1)
        
    else:
        for j in range(m-1,-1,-1):
            l.append(i+1)
            l.append(j+1)
ans = []
x = 0
for i in range(k-1):
    ans.append(l[x:x+6])
    x+=6
ans.append(l[x:])
for i in ans:
    print(len(i),end=" ")
    print(*i)
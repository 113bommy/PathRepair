n,m=map(int,input().split())
a=[input() for i in range(n)]
b=[input() for i in range(m)]
for i in range(n-m+1):
    for j in range(n-m+1):
        x=[]
        for k in range(m):
            x.append(a[i+k][j+m])
        if x==b:
            print("Yes")
            exit()
print("No")

n,m=input().split()
n,m=[int(n),int(m)]
a=[]
for i in range(0,m):
    a.append([int(i) for i in input().split()])
a.sort(key=lambda x:x[1], reverse=True)
c=0
for i in range(0,m):
    if a[i][0]<=n:
        c+=(a[i][0]*a[i][1])
        n=n-a[i][0]
    else:
        c+=(n*a[i][1])
        break
print(c)
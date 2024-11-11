n,m=map(int, input().split())
c=0
for a in range(n+1):
    for b in range(m+1):
        if(a*a+b==n and a+b*b==m):
            c+=1
print(c)            
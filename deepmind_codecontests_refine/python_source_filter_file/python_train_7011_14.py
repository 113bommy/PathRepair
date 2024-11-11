n,m=map(int, input().split())
c=0
for a in range(n):
    for b in range(m):
        if(a*a+b==n and a+b*b==m):
            c+=1
print(c)            
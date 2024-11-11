n,m=map(int,input().split())
l=0
for a in range(n+1):
    for b in range(m+1):
        if (a**2+b==n) and (a+b**2==m):
            l+=1
print(l)

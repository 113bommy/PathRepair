n,m=map(int,input().split())
l=0
for a in range(n):
    for b in range(m):
        if (a**2+b==n) and (a+b**2==m):
            l+=1
print(l)

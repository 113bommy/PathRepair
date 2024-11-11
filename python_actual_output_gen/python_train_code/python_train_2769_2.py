n=int(input())
p=[int(i) for i in input().split()]
s=0
p.sort()
if(n==1):
    print(p[0])
else:
    for i in range(2,n):
        s=s+p[i-2]*2
    s=s+(p[n-1]+p[n-2])*n
    print(s)

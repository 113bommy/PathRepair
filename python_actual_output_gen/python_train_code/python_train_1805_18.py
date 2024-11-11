n=int(input())
l=list(map(int,input().split()))
c=0
m=0
for i in range(n-1):
    if l[i+1]<=2*l[i]:
        c+=1
    else:
        if c>m:
            m=c
        c=0
    if i==n-1:
        if c>m:
            m=c
print(m+1)

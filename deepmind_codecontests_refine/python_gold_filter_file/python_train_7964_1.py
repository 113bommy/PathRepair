n=int(input())
a=list(map(int,input().split()))
ans=0
b=[0 for i in range(n)]
for i in range(n):
    b[a[i]-1]=i
for i in range(1,n):
    ans+=abs(b[i]-b[i-1])
print(ans)

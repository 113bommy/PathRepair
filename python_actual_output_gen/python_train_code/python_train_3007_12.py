n,m=map(int,input().split())
a=[0]*m
for _ in range(n):
    b=list(map(int,input().split()))
    for i in b[1:]:
        a[i]+=1
print(sum(x==n for x in a))
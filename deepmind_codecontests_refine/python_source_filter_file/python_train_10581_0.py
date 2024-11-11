n,m=map(int,input().split())
minn=10**100
for i in range(n):
    a,b=map(int,input().split())
    if a/b<minn:
        minn=a/b 
print(m*a/b)
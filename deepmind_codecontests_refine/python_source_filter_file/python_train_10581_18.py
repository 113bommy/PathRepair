n,m=map(int,input().split())
l=500
for i in range(n):
    a,b=map(int,input().split())
    k=(a/b)*m
    if k<l:
        l=k
print(l)
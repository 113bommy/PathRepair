n,m = map(int,input().split())
a,b = 1,n
for i in range(m):
    l,r = map(int,input().split())
    a,b = max(a,l),min(b,r)
print(b-a+1)
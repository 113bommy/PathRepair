a,b,c=map(int,input().split())
v=list(map(int,input().split()))
p=0
l=0
for i in range(a):
    if v[i]<=b:
        p=p+v[i]
    if p>=c:
        l=l+1
        p=0
print(l)
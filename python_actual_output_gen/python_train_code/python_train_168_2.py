I=lambda:list(map(int,input().split()))
n,l=I()
a,r=I(),0
for i in range(l,n):
    q=0
    for j in range(n):q+=a[j]//i
    r=max(r,q*i)
print(r)
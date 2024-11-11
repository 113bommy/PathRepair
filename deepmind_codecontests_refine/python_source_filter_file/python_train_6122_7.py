n,*s=map(int,open(0).read().split())
m=0
for i in range(1,n):
    t=0
    for j in range(0,n,i):
        k=n-1-j
        if j==k or k%i<1 and k<=j:break
        t+=s[j]+s[k]
        if t>m:m=t
print(m)
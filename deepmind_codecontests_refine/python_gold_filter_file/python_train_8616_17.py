k=int(input())
s=len(input())
c=1
m=10**9+7
p=0
a=[1]
b=[1]
for i in range(k):
    a.append(a[-1]*25%m)
    b.append(b[-1]*26%m)
for i in range(k+1):
    p=(p+a[i]*b[k-i]*c)%m
    c=(c*(s+i)*pow(i+1,m-2,m))%m
print(p)
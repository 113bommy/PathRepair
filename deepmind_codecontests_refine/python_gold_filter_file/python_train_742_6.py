# ASHISH AGARWAL @ashuag007
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[]
x=0
mod=998244353
for i in range (n):
    c.append(a[i]*(i+1)*(n-i))
# print(sorted(c))
# print(sorted(b, reverse=True))
c=sorted(c)
b=sorted(b, reverse=True)
for i in range (n):
    x=x+(c[i]*b[i])
    # print(x)
    x=x%mod
print(x)
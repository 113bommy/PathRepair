N,A,B=map(int,input().split())
v=[int(x)for x in input().split()]
v.sort(reverse=True)
a=sum(v[:A])/A
m=min(v[:A])
k=v.count(m)
l=v.index(m)
ans=0
import math
for i in range(A,B+1):
    if i==A:
        ans+=(math.factorial(k)/math.factorial(i-l))/math.factorial(k-i+l)
    else:
        if k-i+l>=0 and a==m:
            ans+=(math.factorial(k)/math.factorial(i-l))/math.factorial(k-i+l)
        else:
            break
            
            
print("{:.6f}".format(a))
print(int(ans))  
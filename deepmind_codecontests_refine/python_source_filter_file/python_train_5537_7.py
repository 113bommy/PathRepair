from sys import stdin
a1=int(stdin.readline().strip())
a2=int(stdin.readline().strip())
k1=int(stdin.readline().strip())
k2=int(stdin.readline().strip())
n=int(stdin.readline().strip())
a11=a1
a22=a2
k11=k1
k22=k2
n1=max(0,n-((k1-1)*a1)-((k2-1)*a2))
mx=min(n1,a1+a2)

mn=0
k11=min(k1,k2)
if k11==k1:
    mn+=min(a1,n//k1)
    n-=(mn*k1)
    mn+=min(a2,n//k2)
if k11==k2:
    mn+=min(a2,n//k2)
    n-=mn*k2
    mn+=min(a1,n//k1)
print(mx,mn)

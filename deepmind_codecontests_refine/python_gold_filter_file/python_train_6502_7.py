import math
n,m=map(int,input().split())
kmax=((n-m+1)*(n-m))//2
kmin=m*(((n-m)//m+1)*((n-m)//m))//2+math.ceil((n-m)/(m))*((n-m)%m)
print(int(kmin),end=" ")
print(int(kmax))

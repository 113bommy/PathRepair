import math
n,k,l,c,d,p,nl,np=map(int,input().split())
x=(k*l)/nl
y=(c*d)
z=p/np
ans=(min(x,y,z))/n
print(math.floor(ans))
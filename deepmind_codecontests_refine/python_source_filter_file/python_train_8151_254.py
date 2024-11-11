import math
n,k,l,c,d,p,nl,np=map(int,input().split())
x=(k*l)/n
y=(c*d)
z=p/np
ans=(min(x,y,z))/nl
print(math.floor(ans))
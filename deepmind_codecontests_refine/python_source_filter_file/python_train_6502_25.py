import math
m,n = map(int,input().split())
#maxium
maxium = (m-n+1)*(m-n)/2
#minium
A = math.ceil(m/n)
Bcnt = A*n-m
Acnt = n-Bcnt
B = A - 1
minium = A*(A-1)/2*Acnt+B*(B-1)/2*Bcnt

print(int(minium),int(maxium))

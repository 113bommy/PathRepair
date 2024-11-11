import math,sys
n,v = map(int,input().split())
rs = v
litre = v
i = 1
if n<=v-1:
    print(n-1)
    sys.exit()
while litre<n-1:
    i+=1
    litre  = litre + 1
    rs = rs+i
print(rs)

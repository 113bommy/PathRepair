# import os


n,k = map(int, input().split())

c =0
if (n*2) % k == 0:
    c += (n*2)//k
else:
    c += (n*2)//k+1
if (n*5) % k == 0:
    c += (n*5)//k
else:
    c += (n*5)//k+1
if (n*8) % k == 0:
    c += (n*8)//k
else:
    c += (n*8)//k+1


# 22 
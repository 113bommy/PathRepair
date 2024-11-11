import sys
import math as m
MOD = int(1e9+7)
n = input()
l = len(n)
f = [0]*(1000001)
f[0] = 0
f[1] = 1
pos = 10
for i in range(2,l):
    f[i] = (f[i-1]+(i*pos)%MOD)%MOD
    pos = (pos*10)%MOD
ans_ = int(0)
pos_ = 1
for i in range(l-1,-1,-1):
    if i == 0:
        tmp1 = 0
    else:
        tmp1 = (((i*(i+1)/2)%MOD*int(n[i])%MOD)%MOD*pos_)%MOD
    tmp2 = (int(n[i])*f[l-1-i])%MOD
    ans_ = ((ans_+tmp1)%MOD+tmp2)%MOD
    pos_ = (pos_*10)%MOD
print((ans_))

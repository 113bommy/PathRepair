import math
k,d,t = [int(x) for x in input().split(' ')]
v = (d*math.ceil(k/d))
cyc = k + ((v-k)/2)
a = (t//cyc)
c = t-(a*cyc)-k
ans = 0
if c>0:
    ans = c
print(k+c+(a*v)+ans)
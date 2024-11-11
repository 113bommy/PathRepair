import math
n,m,a = ((input()).split())
#print(n,m,a)
n= int(n)
m= int(m)
a = int(a)
lentile = math.ceil( n/a )
print('lentile',lentile)
bredthtile = math.ceil( m/a )
print('bredthtile',bredthtile)
total = lentile*bredthtile
if total==0:
    total = 1

print(total)

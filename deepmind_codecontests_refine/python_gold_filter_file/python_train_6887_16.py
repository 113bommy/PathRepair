from math import *
k = int(input())
l = int(input())

x = log(l)/log(k)
xx = round(x)
#print(x,xx)
print( ('YES\n%d' % (xx-1)) if abs(x-xx)<1e-12 else 'NO' )

#  C:\Users\Usuario\HOME2\Programacion\ACM
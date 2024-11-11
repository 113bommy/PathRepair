from math import sin,radians
n,r=map(int,input().split())
angle=(360/(2*n))
print(angle)
res=(r*sin(radians(angle)))/(1-sin(radians(angle)))
print(res)
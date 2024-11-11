from math import*
a,b,x=map(int,input().split())
print(atan(2*(b/a-x/a**3)*(x>a*a*b/2)or a*b*b/2/x)/pi*180)
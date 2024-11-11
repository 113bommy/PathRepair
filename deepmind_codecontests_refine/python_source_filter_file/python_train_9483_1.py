R=lambda:map(int,input().split())
R()
c,a=R(),R()
r=0
try:
 for x in a:r+=next(1 for y in c if y<=x)
except:print(r)
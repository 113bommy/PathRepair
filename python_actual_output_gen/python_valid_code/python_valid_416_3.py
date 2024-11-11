t,T,a,A,b,B=map(int, open(0).read().split())
x,y=(a-b)*t,(A-B)*T
if x+y==0:
 r="infinity"
else:
 s,t=divmod(-y, x+y)
 r=0 if s<0 else s*2+(1 if t else 0)
print(r)
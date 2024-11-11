n,*a=map(int,open(0).read().split())
b,m=sum(a),n*-~n//2
n-=1
c=b//m
f=b%m>0
for i,j in zip(*[iter([a[-1]]+a*2)]*2):
  j-=i
  if n:
    t=j//n
    f|=c!=j+n*-t-t
print('YNEOS'[f::2])
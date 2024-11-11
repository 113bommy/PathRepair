N=int(input())
L=list(map(int,input().split()))
L=[i//400 for i in L]
a=[i for i in L if i<8]
b=[i for i in L if i>7]
a=len(set(a))
b=len(b)
if a==0:
  mi=1
  ma=b
else:
  mi=a
  ma=min(8,mi+b)
print(mi,ma)
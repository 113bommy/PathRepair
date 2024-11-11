x,k,d=map(int,input().split())
p=k*d-x
q=p//(2*d)
r=p//(2*d)
if r<=0:
  print(-p)
elif 0<r<=k:
  s=min(p-2*d*q,-p+2*d*(q+1))
  print(s)
else:
  print(x+k*d)

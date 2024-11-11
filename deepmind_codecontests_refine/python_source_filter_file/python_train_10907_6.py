x,k,d=map(int,input().split())
x=abs(x)
t=x-k*d
if t>=0:
  print(t)
else:
  td=x%d
  tk=x//d
  if (k-tk)%2==0:
    print(tk)
  else:
    print(abs(td-d))
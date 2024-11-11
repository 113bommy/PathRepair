X,Y=map(int,input().split())
A,B=1,1
mod=10**9+7
if (X+Y)%3 ==0:
    x=(2*Y-X)//3
    y=(2*X-Y)//3
    if min(x,y) !=0:
      for i in range(min(x,y)):
        A*=(x+y-i)
        A%=mod
        B*=(i+1)
        B%=mod
      print(A*pow(B,mod-2,mod)%mod)
    else:
      print(1)
else:
  print(0)
    
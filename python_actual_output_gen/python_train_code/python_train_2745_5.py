X,Y=map(int,input().split())
if 2*Y<=X or 2*X<=Y or not((2*Y-X)%3==0) or not((2*X-Y)%3==0):
  print(0)
else:
  A=(2*Y-X)//3
  B=(2*X-Y)//3
  k=1
  for i in range(A+1,A+B+1):
    k=(k*i)%1000000007
  j=1
  for i in range(1,B+1):
    j=(j*i)%1000000007
  l=(pow(j,1000000005,1000000007)*k)%1000000007
  print(l)
  
A,B,C,K=map(int,input().split())
if K<=A+B:
  print(int(A))
else:
  print(int(A-(K-(A+B))))
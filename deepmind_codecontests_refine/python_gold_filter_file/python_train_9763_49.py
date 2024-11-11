A,B,C,K=map(int,input().split())
if K<=A:
  print(int(K))
else:
  print(int(A-(K-(A+B))))
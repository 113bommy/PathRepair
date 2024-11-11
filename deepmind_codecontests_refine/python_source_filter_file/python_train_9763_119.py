A,B,C,K=list(map(int,input().split()))
if A+B>=K:
  print(A)
  exit()
print(A-(K-(A+B)))

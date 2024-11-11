A,B,C,K = map(int,input().split())
if A>=K:
  print(A)
elif A+B>=K:
  print(K)
else:
  print(2*A+B-K)
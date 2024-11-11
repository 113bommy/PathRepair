S = int(input())
 
A = [0,0,1]
if S == 1 or S == 2:
  print(0)
elif S == 3:
  print(1)
else:
  for i in range(3,S):
    A += [A[i-1] + A[i-3]]
  print(A[i] % (10 ** 9 + 7))
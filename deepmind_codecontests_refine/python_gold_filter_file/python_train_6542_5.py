N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
odd = len([a for a in A if a %2 == 1])
 
if K == 0 and odd == 0:
  print(2**N)
elif K == 1 and odd == 0:
  print(0)
else:
  print(2**(N-1))
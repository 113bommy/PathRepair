N = int(input())
A = 0
for i in range(1,N+1):
  if len(str(i)) % 2 == 1:
    A += 1
print(A)
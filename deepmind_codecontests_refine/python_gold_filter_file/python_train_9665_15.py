N = int(input())
A = set()
for i in range(N):
  x = int(input())
  if x in A:
    A.remove(x)
  else:
    A.add(x)
print(len(A))

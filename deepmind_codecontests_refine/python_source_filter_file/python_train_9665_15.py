N = int(input())
A = set()
for i in range(N):
  x = int(input())
  if x in A:
    A.remove(x)
  else:
    A.append(x)
print(len(A))
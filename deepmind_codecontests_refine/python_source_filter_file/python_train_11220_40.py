input()
A = list(map(int, input().split()))
A = A.sorted()
p = 1
for i in A:
  p *= i
  if p > 10**18:
    p = -1
    break
print(p)
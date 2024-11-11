u = int(input())
A = list(map(int,input().split()))
count = 0
for a in range(u-1):
  a = A.pop()
  if a == A[-1]:
    A[0] = -1
    count += 1
print(count)
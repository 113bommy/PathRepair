n, d = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
min_res = 1000000000000000000000000000000000000000000000000000000000
for i in range(len(A)):
  for j in range(len(A)):
    if abs(A[i] - A[j]) <= d:
      if min(i, j) + len(A) - max(i, j) - 1 < min_res:
        min_res = min(i, j) + len(A) - max(i, j) - 1
        
print(min_res)
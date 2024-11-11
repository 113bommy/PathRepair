A = []
for _ in range(3):
  A += list(map(int, input().split()))
N = int(input())
res = "No"

for _ in range(N):
  b = int(input())
  if b in A:
    ind = A.index(b)
    A[ind] = -1
if any(all(a==-1 for a in A[3*i:i+3])for i in range(3)): res = "Yes"
if any(all(a==-1 for a in A[i::3])for i in range(3)): res = "Yes"
if any(all(A[i]==-1 for i in a)for a in [[0,4,8],[2,4,6]]): res = "Yes"
print(res)
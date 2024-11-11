N, M = map(int, input().split())
A = list(map(int, input().split()))
BC = [[] for _ in range(M)]
for i in range(M):
  BC[i] = list(map(int, input().split()))

BC.sort(key=lambda x: x[1], reverse=True)

for i in BC:
  A.extend([i[1]]*i[0])
  if len(A) > N:
    break
    
A = sorted(A,reverse=True)
print(sum(A[:N]))


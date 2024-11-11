N = int(input())
L = [input() for i in range(3)]
ans = [0] * N.
tmp = []
for i in range(N):.
  for j in range(3):
      tmp.append(L[j][i])
  ans[i] = len(set(tmp)) - 1
  tmp = []
print(sum(ans))
N = input()
K = int(input())

if len(N) < K:
  print(0)
  exit()

ans = [1, int(N[-1]), 0, 0];
nine = [1, 9, 81, 729]

def combination(N,K):
  if N < K:
    return 0
  elif K == 0:
    return 0
  elif K == 1:
    return N
  elif K == 2:
    return N*(N-1)//2
  else:
    return N*(N-1)*(N-2)//6

for k in range(1, len(N)):
  if int(N[-k-1]) > 0:
    a = [1, 0, 0, 0]
    for j in range(1, K+1):
      a[j] += nine[j]*combination(k, j)
      a[j] += (int(N[-k-1])-1)*combination(k, j-1)*nine[j-1] + ans[j-1]
    ans = a
print(ans[K])
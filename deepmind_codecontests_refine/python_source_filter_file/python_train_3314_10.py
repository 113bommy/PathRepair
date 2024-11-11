from collections import Counter
N, K = map(int, input().split())
A = list(map(int, input().split()))
dA = Counter(A)
if len(dA) - K <= 0:
  print(0)
  exit()
print(sum(sorted(dA.values())[:len(dA)-K])))
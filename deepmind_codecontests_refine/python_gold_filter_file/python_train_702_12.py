from collections import Counter

n = int(input())
a = list(map(int,input().split()))
q = int(input())

C = Counter(a)
s = sum(a)

for _ in range(q):
  b,c = map(int,input().split())
  s = s - b*C[b] + c*C[b]
  C[c] += C[b]
  C[b] = 0
  print(s)
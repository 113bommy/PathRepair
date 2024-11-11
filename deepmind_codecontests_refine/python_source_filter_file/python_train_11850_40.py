N, M = map(int, input().split())
ls = []
for i in range(1,M):
  if M%i==0:
    j = M//i
    if i<=M//N:
      ls += [i]
    if j<=M//N:
      ls += [j]
  if M**0.5<i:
    break
print(max(ls))

n,m = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

b.sort()

low = b[0]
high = b[-1]

ans = []

for i in range(n):
  best = -10000000000000000000001
  for j in range(n):
    if i != j:
      best = max([best, low*a[j], a[j]*high])
  ans.append(best)
print(min(ans))

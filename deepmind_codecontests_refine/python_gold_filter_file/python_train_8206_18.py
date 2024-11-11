n = int(input())
a = list(map(int, input().split()))

total = sum(a)
ans = []
for x in range(n-1):
  total -= 2*a[x]
  ans.append(abs(total))

print(min(ans))
n, d = map(int, input().split())
a = sorted(map(int, input().split()))
m = int(input())
if m >= n:
  print(sum(a) - d * (m-n))
else:
  print(sum(a[:m+1]))

  
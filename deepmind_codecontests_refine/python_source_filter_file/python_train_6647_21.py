n = int(input())
a = list(map(int, input().split()))
k = sum(a) // (n*(n+1)//2)
if n*(n+1)*k // 2 != sum(a):
  print('NO'); exit(0)
b = [a[i] - a[i-1] - k for i in range(n)]
for x in b:
  if x%n: print('NO'); break
else:
  print('YES')
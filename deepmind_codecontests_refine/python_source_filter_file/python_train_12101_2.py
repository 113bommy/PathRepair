t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  arr = [0]*10**4
  for i in range(1,n+1):
    k -= i
    if k < 0: break
    if k == 0: break
  if i == n and k == 0:
    a = 0
    b = 1
  elif k == 0:
    a = n - 1 - i
    b = a + 1
  elif k < 0:
    k += i
    a = n - 1 -i
    b = n - k
  s = ['a'] * n
  s[a] = 'b'
  s[b] = 'b'
  print(*s)
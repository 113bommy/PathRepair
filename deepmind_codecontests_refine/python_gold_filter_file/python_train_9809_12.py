t = int(input())

for _ in range(t):
  n, x = list(map(int, input().split()))
  s = list(map(int, input()))
  bal = [0] * (n + 1)
  cnt = 1 if x == 0 else 0
  for i in range(n):
    if s[i] == 0:
      bal[i+1] = bal[i] + 1
    else:
      bal[i+1] = bal[i] -1
    if bal[i+1] == x:
      cnt += 1
  #print(bal)
  b = bal[-1]
  if b == 0 and cnt > 0:
    print(-1)
  elif b == 0 and cnt == 0:
    print(0)
  elif b != 0:
    for i in range(n):
        rest = x - bal[i+1]
        k = rest // b
        #print(x, bal[i+1], rest, rest % b, k, bal[i+1] + k * b)
        if rest % b == 0 and k > 0:
            cnt += 1
    print(cnt)
  else:
    print(cnt) 
#01:15
n,k = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n):
  a[i] -= 1
  a[i] %= k
b = [0]
for i in range(n):
  b.append((b[-1]+a[i]) % k)
ans = 0
now = {0:1}
for i in range(1,n+1):
  tmp = b[i]
  if tmp in now:
    ans += now[tmp]
    now[tmp] += 1
  else:
    now[tmp] = 1
  if i - k + 1 >= 0:
    now[b[i-k+1]] -= 1
print(ans)
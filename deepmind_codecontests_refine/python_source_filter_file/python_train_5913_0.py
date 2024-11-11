#解説解答
n,k = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n):
  a[i] -= 1
  a[i] %= k
#print(a)
b = [0]
for i in range(n):
  b.append((b[-1]+a[i])%k)
#print(b)

ans = 0
now = {0:1}
for i in range(1,n+1):
  if b[i] in now:
    ans += now[b[i]]
    now[b[i]] += 1
  else:
    now[b[i]] = 1
  if i - k + 1 >= 0:
    now[b[i-k+1]] -= 1
  #print(now,i,ans)
print(ans)
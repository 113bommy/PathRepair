n, p = map(int, input().split())
s = input()
x = [1] + [0]*(p-1)
ans = 0
u = 0
if p in [2,5]:
  for i in range(n):
    if int(s[i])%p==0:
      ans += i+1
else:
  for i in range(n-1,-1,-1):
    u = (int(s[i])*10**(n-1-i)+u)%p
    ans += x[u]
    x[u] += 1
print(ans)
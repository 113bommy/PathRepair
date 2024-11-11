n,k = map(int,input().split())
a = list(map(int,input().split()))

s = sorted(a,reverse=True)
mod = 10**9 + 7
ans = 1

if k % 2 == 1 and s[0] < 0:
        for i in range(k):
            ans = ans * s[i] % mod
        print(ans)
        exit()

l = 0
r = n - 1
if k % 2 == 1:
  ans = ans * s[r]
  r -= 1

for _ in range(k // 2):
  ml = s[l] * s[l + 1]
  mr = s[r] * s[r - 1]
  if ml > mr:
    ans = ans * ml % mod
    l += 2
  else:
    ans = ans * mr % mod
    r -= 2

print(ans)
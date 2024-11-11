n = int(input())
s = input()
mod = 998244353
ans = 1
z, o, t = n, 0, 0
pre = ["", ["", ""]]
for i in range(3*n):
  if t != 0 and s[i] not in pre[1]:
    ans *= t
    ans %= mod
    t -= 1
    if t == 0:
      pre[1] = ["", ""]
  elif s[i] == pre[0] or o == 0:
    o += 1
    ans *= z
    ans %= mod
    z -= 1
    pre[0] = s[i]
  else:
    t += 1
    ans *= o
    ans %= mod
    o -= 1
    pre[1] = [pre[0], s[i]]
    if o == 0:
      pre[0] = ""

print(ans)
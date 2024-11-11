def factorial(n):
  ans = 1
  for i in range(n):
    ans *= i+1
    ans %= mod
  return ans


mod = 998244353
n = int(input())
s = input()
ans = 1
r,g,b = 0,0,0
rg,rb,gb = 0,0,0
for i in s:
  if i == "R":
    if gb > 0:
      ans *= gb
      gb -= 1
    elif g > 0:
      ans *= g
      g -= 1
      rg += 1
    elif b > 0:
      ans *= b
      b -= 1
      rb += 1
    else:
      r += 1
  elif i == "G":
    if rb > 0:
      ans *= rb
      rb -= 1
    elif r > 0:
      ans *= r
      r -= 1
      rg += 1
    elif b > 0:
      ans *= b
      b -= 1
      gb += 1
    else:
      g += 1
  elif i == "B":
    if rg > 0:
      ans *= rg
      rg -= 1
    elif r > 0:
      ans *= r
      r -= 1
      rb += 1
    elif g > 0:
      ans *= g
      g -= 1
      gb += 1
    else:
      b += 1
    ans %= mod 
print((factorial(n) * ans) % mod)

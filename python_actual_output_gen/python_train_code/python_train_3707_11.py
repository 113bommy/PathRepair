n = int(input())

s = []
for i in range(2, int(n**0.5)+1):
  t = 0
  while n%i == 0:
    n //= i
    t += 1
  s.append(t)
  if n == 1: break

if n > 1: s.append(1)
  
ans = 0
for i in s:
  for j in range(1, i+1):
    if i >= j:
      i -= 1
      ans += 1
    else:
      break
print(ans)
input()

ans = 0
x = 0
for c in input():
  if c == 'D':
    x += 1
  else:
    x -= 1
  ans = max(ans, x)
  
print(ans)
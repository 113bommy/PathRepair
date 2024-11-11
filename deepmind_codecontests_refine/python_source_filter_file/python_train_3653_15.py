a, b, x = map(int, input().split())
s = ''
if a < b: #10101
  a -= (x + 1) // 2
  b -= x // 2 + 1
  for i in range(x + 1):
    if i == 0:
      s = '1' * (a + 1)
    elif i == 1:
      s += '0' * (b + 1)
    else:
      s += '0' if i % 2 else '1'
else:
  a -= x // 2 + 1
  b -= (x + 1) // 2
  for i in range(x + 1):
    if i == 0:
      s = '0' * (b + 1)
    elif i == 1:
      s += '1' * (a + 1)
    else:
      s += '1' if i % 2 else '0'
  
print(s)

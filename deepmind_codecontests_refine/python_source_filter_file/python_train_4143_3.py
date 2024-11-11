H = int(input())
i = 0
while H > 1:
  H = -(-H//2)
  i += 1
print(2**i-1)
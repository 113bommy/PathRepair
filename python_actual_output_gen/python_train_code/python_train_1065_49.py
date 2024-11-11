cost = { 'Q': 9, 'R': 5, 'B': 3, 'N': 3, 'P': 0, 'K': 0, '.': 0 }
line = ''.join(input() for i in range(8))
c1 = c2 = 0
for c in line:
  if c.isupper():
    c1 += cost[c]
  else:
    c2 += cost[c.upper()]
print("White" if c1 > c2 else "Black" if c1 < c2 else "Draw")
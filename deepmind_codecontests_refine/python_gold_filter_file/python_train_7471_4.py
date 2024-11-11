a = 1; b = c = 0
for _ in range(int(input()) - 2):
  a, b, c = b, c, (a + c) % (10**9 + 7)
print(c)

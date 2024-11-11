a = b = 0; c = 1
for _ in range(int(input()) - 3):
  a, b, c = b, c, (a + c) % (10**9 + 7)
print(c)

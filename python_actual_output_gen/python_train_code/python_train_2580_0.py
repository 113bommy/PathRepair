s = int(input())
a = b = 0; c = s > 2
for _ in range(s - 3):
  a, b, c = b, c, (a + c) % (10**9 + 7)
print(c)

k = int(input())
i = 1
a = 7
a %= k
while a != 0:
  i += 1
  a = (10*a + 7) % k
  if i == 10**9+7:
    i = -1
    break

print(i)
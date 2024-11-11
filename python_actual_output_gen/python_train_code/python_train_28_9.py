k = "a",
for _ in range(int(input()) - 1):
  k = {a + b for a in r for b in a + chr(ord(max(a)) + 1)}
print(*sorted(k), sep='\n')
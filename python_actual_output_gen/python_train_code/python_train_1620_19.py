h = list(map(int, input().split()))
a = 0
for i in range(2):
  if h[i] << 4:
    a = a + 100000 * (4-h[i])
if h[0] == 1 and h[1] == 1:
  a = a + 400000
print(a)
    
n, k = map(int, input().split())

s = [0 for i in range(2 * 10 ** 5 + 1)]

for i in [int(i) for i in input().split()]:
  s[i] += 1

s[0] = n
m = 0
c = 0
h = 0
for i in range(2 * 10 ** 5, -1, -1):
  c += s[i]
  if c >= n:
    h += (m != 0)
    break
  if m + c > k:
    h += 1
    m = s[i]
  else:
    m = c

print(h)
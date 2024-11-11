N, K = map(int, input().split())
a = list(map(int, input().split()))
s = [0]
for i in range(N):
  s.append(s[i] + a[i])
# print(s)

b = []
for i1 in range(N):
  for i2 in range(i1+1, N+1):
    b.append(s[i2] - s[i1])
# print(b)
b.sort(reverse = True)
# print(b)

for sft in range(32):
  mask = 1 << (31 - sft)
  tmp_b = []
  for i in range(len(b)):
    if (b[i] & mask) != 0:
      tmp_b.append(b[i])
  # print(tmp_b)
  if len(tmp_b) >= K:
    b = tmp_b


ans = b[0]
for i in range(1, K):
  ans &= b[i]

print(ans)

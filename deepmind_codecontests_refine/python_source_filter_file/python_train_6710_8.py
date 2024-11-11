def bit_diff(n, k, ml):
  a = []
  b = []
  while n > 0:
    a.append(n % 2)
    n //= 2
  while k > 0:
    b.append(k % 2)
    k //= 2
  while len(b) < n:
    b.append(0)
  while len(a) < n:
    a.append(0)
  ans = 0
  for i in range(n):
    ans += a[i] != b[i]
  return ans
n = int(input())
val = input()[::-1]
kl = int(val, 2)
print (abs(bit_diff(kl, kl + 1, n)))
a = list(map(int, input().split()))
b = a[0]
while b % a[1] != 0:
  b += a[0]
print(b)

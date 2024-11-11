import math
L = int(input())

n = int(math.log2(L))
w1 = pow(2,n-1)
w1n = bin(L - pow(2, n))
p = 2 * n  + w1n.count('1') + 1
print(str(n + 1) + " " + str(p))

print("1 2 0")
print("1 2 " + str(w1))
for i in range(2, n + 1):
  print(str(i) + " " + str(i + 1) + " 0")
  print(str(i) + " " + str(i + 1) + " " + str(pow(2, n - i)))

w = L - 1
for i in range(len(w1n) - 2):
  if w1n[-1] == '1':
    print("1 " + str(n + 1 - i) + " " + str(w))
    w -= pow(2, i)
  w -= pow(2, i)
  w1n = w1n[:-1]
  if w1n.count('1') == 0:
    break
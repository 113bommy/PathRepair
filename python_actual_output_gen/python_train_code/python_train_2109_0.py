X = int(input())
K = 0
while ((X * K) % 360 != 0) and (K == 0):
  K += 1
print(K)
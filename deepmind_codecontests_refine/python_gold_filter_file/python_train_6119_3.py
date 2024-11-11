X = int(input())
K = 0
while ((X * K) % 360 != 0) or (K == 0):
  K += 1
print(K)
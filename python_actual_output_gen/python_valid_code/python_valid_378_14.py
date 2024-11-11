N = int(input())
for i in range(int(N**0.5)+1, 1, -1):
  if N % i == 0:
    print(i + (N // i) - 2)
    break

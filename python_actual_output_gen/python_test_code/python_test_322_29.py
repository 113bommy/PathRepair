N, M = map(int, input().split())

for i in range(M, 0, -1):
  if M % i == 0:
    print(i)
    exit()
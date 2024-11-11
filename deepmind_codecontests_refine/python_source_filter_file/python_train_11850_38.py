N, M = map(int, input().split())

start = M // N
for i in range(start, 0, -1):
    if M % i == 0:
        print(i)
        break

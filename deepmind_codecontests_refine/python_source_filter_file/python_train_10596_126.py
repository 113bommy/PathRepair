N, K = map(int, input().split())

i = 1
while K**i < N:
    i += 1

print(i)

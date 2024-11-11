t = int(input())

for _ in range(t):
    n = int(input())
    print(*[i for i in range(100, 100-n, -1)])
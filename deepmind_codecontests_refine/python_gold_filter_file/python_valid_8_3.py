def polycarp(N):
    n = N//3
    r = N % 3
    if r <= 1:
        return [n+r, n]
    else:
        return [n, n+1]


N = int(input())

for _ in range(N):
    print(*polycarp(int(input())))


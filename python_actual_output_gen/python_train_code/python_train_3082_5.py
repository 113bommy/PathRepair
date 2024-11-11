n = int(input())
p = list(map(int, input().split()))
for i in range(n):
    used = [0] * n;
    x = i
    while (used[x] == 0):
        used[x] = 1
        x = p[x] - 1
    print(x, end=' ')
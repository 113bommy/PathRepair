n = int(input())
p = list(map(int, input().split()))

x = sum(abs(i * 2 - p[i] + 1) for i in range(n//2))
y = sum(abs(i * 2 + 1 - p[i] + 1) for i in range(n//2))

print(min(x, y))
    
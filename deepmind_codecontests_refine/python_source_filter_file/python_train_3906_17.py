I = lambda: map(int, input().split())

n, s = I()

print(min(s, max(sum(I()) for _ in range(n))))
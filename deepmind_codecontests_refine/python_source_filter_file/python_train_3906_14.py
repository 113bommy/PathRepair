I = lambda: map(int, input().split())

n, _ = I()

print(max(sum(I()) for _ in range(n)))
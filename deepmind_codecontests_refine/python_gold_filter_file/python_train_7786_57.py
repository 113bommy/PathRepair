L = 10 ** 9
N = int(input())
y = (N - 1) // L + 1
x = (-N) % L
print(0, 0, L, 1, x, y)
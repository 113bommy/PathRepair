n, m = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

mod = 10 ** 9 + 7

x_sum = 0
for i in range(n-1):
    x_sum += (x[i+1] - x[i]) * (i + 1) * (n - i - 1)
    x_sum %= mod

y_sum = 0
for i in range(m-1):
    y_sum += (y[i+1] - y[i]) * (i + 1) * (m - i - 1)
    y_sum %= mod

print((x_sum * y_sum) % mod)
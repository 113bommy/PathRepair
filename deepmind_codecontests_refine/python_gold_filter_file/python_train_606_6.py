n, m = list(map(int, input().split()))
x = list(map(int, input().split()))
y = list(map(int, input().split()))

sum_x = 0
for i in range(0, n):
    sum_x += i * x[i] - (n - (i + 1)) * x[i]

sum_y = 0
for i in range(0, m):
    sum_y += i * y[i] - (m - (i + 1)) * y[i]

ans = sum_x * sum_y

divide_num = pow(10, 9) + 7
print(ans % divide_num)

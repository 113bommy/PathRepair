n, k = map(int, input().split())
a = list(map(int, input().split()))
s = 0
b = [0] * (n + 1)
for i in range(1, n + 1):
    s += a[i - 1]
    b[i] = s
opt_sum = 0
opt_num = k
for i in range(k, n + 1):
    for j in range(n - i + 1):
        s = b[j + k] - b[j]
        temp_sum = s * opt_num
        temp_opt_sum = opt_sum * i
        if temp_sum > temp_opt_sum:
            opt_sum = s
            opt_num = i
print(opt_sum / opt_num)
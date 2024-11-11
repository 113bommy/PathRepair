def calc_sum(x):
    sum = 0
    while x > 0:
        sum += x % 10
        x //= 10
    return sum


a, b, c = map(int, input().split(' '))

ans = []

for sum in range(1, 72):
    x = b * (sum ** a) + c
    if calc_sum(x) == sum and x < 10 ** 9:
        ans.append(x)

print(len(ans))

for item in ans:
    print(item, end = ' ')
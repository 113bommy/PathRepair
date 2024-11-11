n = int(input())
counts = [0] * n
temp1 = 810
temp2 = 1800
counts[-1] = 10
if n >= 2:
    counts[-2] = 180
for i in range(n - 2, 0, -1):
    counts[i - 1] = (n - i - 1) * temp1 + temp2
    counts[i - 1] %= 998244353
    temp1 *= 10
    temp2 *= 10
    temp1 %= 998244353
    temp2 %= 998244353
for item in counts:
    print(item, end = ' ')

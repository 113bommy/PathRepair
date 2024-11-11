x = [4, 1, 3, 0, 2, 5]
n = (bin(int(input()))[2:][::-1] + '000000')[:6]
y = [0] * 6
for i in range(6):
    y[x[i]] = n[i]
print(int(''.join(y)[::-1], 2))

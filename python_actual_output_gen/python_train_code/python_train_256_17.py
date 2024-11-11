n = int(input())
x2, x4, x = 0, 0, 0

for num in input().split(' '):
    tmp = int(num)
    x2 += tmp % 2 == 0 and tmp % 4 != 0
    x4 += tmp % 4 == 0
    x += tmp % 2 != 0

print("Yes" if x + (x2 != 0) == x4 + 1 else "No")

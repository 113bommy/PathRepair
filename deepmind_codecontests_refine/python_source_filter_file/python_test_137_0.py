x, y = map(int, input().split())
x = bin(x)[2:]
y = bin(y)[2:]

if x == y:
    print("YES")
    exit(0)

for var in [y + '1', y.strip('0')]:
    for left in range(len(y) - len(x) + 1):
        right = len(y) - len(var) - left
        if '1' * left + var + '1' * right == y or '1' * left + var[::-1] + '1' * right == y:
            print("YES")
            exit(0)
print("NO")

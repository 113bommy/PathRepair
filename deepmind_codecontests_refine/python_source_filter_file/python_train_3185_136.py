l, b = map(int, input().split())
y = 0
while b > l:
    y += 1
    b = b * 2
    l = l * 3
print(y)


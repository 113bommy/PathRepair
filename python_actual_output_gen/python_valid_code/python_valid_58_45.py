n = int(input())
x = 0
for i in range(n):
    if input() == '++X':
        x += 1
    else:
        x -= 1
print(x)
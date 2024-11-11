y = 0
x = 0
n = int(input())
for i in range(n):
    a = str(input())
    if a == '++x' or a == 'x++':
        y = y + 1
    elif a == '--x' or a == 'x--':
        x = x - 1

print(x+y)

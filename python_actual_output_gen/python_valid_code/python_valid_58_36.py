n = int(input())
x = 0
for i in range(n):
    s = str(input())
    if s[0] == 'x':
        if s[1] == '+':
            x = x + 1
        else:
            x = x - 1
    else:
        if s[0] == '+':
            x = x + 1
        else:
            x = x - 1
print(x)
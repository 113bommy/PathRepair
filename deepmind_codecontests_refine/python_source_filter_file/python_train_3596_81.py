n, x = map(int, input().split())
m = 0
for i in range(n):
    y = input().split()
    if y[0] == "+":
        x += int(y[1])
    else:
        if int(y[1]) < x :
            x -= int(y[1])
        else:
            m += 1
print(x, m)
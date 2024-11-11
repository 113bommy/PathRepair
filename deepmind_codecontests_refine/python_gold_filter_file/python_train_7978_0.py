n = int(input())
s = input()
x, y, last, count = 0, 0, 0, 0
for i in range(n):
    if s[i] == 'R':
        x += 1
    else:
        y += 1
    if last == 0:
        if y == 1:
            last = 1
        else:
            last = 2
    if last == 1 and x > y:
        last = 2
        count += 1
    elif last == 2 and x < y:
        last = 1
        count += 1
print(count)





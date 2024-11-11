field = [['#']*100 for _ in range(50)] + [['.']*100 for _ in range(50)]

a, b = map(int, input().split())
a-=1
b-=1
x = 0
y = 0
for _ in range(a):
    field[x][y] = '.'
    y += 2
    if y >= 100:
        y = 0
        x += 2

x = 99
y = 0
for _ in range(a):
    field[x][y] = '#'
    y += 2
    if y >= 100:
        y = 0
        x -= 2

print(100,100)
        
for row in field:
    print("".join(row))

        

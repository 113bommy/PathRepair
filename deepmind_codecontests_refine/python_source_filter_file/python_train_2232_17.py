input1 = input().split()
x = []
for c in input1:
    x.append(int(c))
input2 = input()
y = []
for c in input2:
    y.append(int(c))
win = 0
for b in y:
    if b == 1:
        win = win + x[0]
    elif b == 2:
        win = win + x[1]
    elif b == 3:
        win = win + x[2]
    else:
        win = win + x[3]

print(y)
print(win)











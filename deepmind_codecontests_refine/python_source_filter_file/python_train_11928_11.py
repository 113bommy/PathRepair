import math

n = int(input())
c, d = [], []
no = False
for _ in range(0, n):
    string = list(map(int, input().split()))
    c.append(string[0])
    d.append(string[1])
if all([x == 1 for x in d]):
    print('Infinity')
elif n == 1:
    print('1899') # !!!
else:
    if d[0] == 1:
        x = (1900, math.inf)
    else:
        x = (-math.inf, 1899)
    div = d[0]
    for i in range(0, n-1):
        x_next = x
        if d[i] == 1 and d[i+1] == 2:
            x_next = x[0]+c[i], min(1899, x[1]+c[i])
        elif d[i] == 2 and d[i+1] == 1:
            x_next = max(1900, x[0]+c[i]), x[1]+c[i]
        else:
            x_next = max(x[0] + c[i], 1900) if d[i+1] == 1 else x[0] + c[i], min(x[1] + c[i], 1899) if d[i+1] == 2 else x[1] + c[i]
        if (x_next[0] > x_next[1]):
            no = True
            break
        else:
            x = x_next

    print('Impossible' if no else x[1] + c[-1])

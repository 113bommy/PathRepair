
n = int(input())

x = [int(x) for x in input().split()]

x.append(-1)
rest = 0
if x[0] == 0:
    rest = rest + 1

for i in range(1 , n):
    if x[i] == 0:
        rest = rest + 1
    elif x[i] == 1 and x[i - 1] == 1:
        rest = rest + 1
        x[i] = 0
    elif x[i] == 2 and x[i - 1] == 2:
        rest = rest + 1
        x[i] = 0
    elif x[i] == 3:
        if x[i - 1] == 1:
            x[i] = 2
        elif x[i - 1] == 2:
            x[i] = 1
        elif x[i - 1] == 0 and x[i + 1] == 2:
            x[i] == 1
        elif x[i - 1] == 0 and x[i + 1] == 1:
            x[i] == 2
            
print(rest)
        
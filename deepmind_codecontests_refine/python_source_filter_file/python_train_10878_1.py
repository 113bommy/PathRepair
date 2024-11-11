n = int(input())
s = set()
inRoom = 0
count = 0
for _ in range(n):
    y = input()
    if y[0] == '+':
        inRoom += 1
        if inRoom > count:
            count += 1
        s.add(y[2:])
    else:
        if y[2:] not in s:
            count += 1
        else:
            s.remove(y[2:])
        inRoom -= 1
    
print(count)

    
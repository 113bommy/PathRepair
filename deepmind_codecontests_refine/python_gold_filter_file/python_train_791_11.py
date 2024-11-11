n = int(input())
data = []
number = -1
for i in range(n):
    data.append({int(z) for z in input().split()})
for a in range(1, 10):
    for i in range(n):
        if a in data[i]:
            break
    else:
        number = a
        break
if number != -1:
    print(number - 1)
    exit(0)
for a in range(10, 100):
    r = a % 10
    l = a // 10
    lk = []
    rk = []
    for i in range(n):
        if l in data[i]:
            lk.append(i)
        if r in data[i]:
            rk.append(i)
    if len(lk) >= 2 and len(rk) >= 1 or len(rk) >= 2 and len(lk) >= 1:
        continue
    elif len(lk) >= 1 and len(rk) >= 1:
        if lk != rk:
            continue
        else:
            number = a
            break
    else:
        number = a
        break
print(number - 1)

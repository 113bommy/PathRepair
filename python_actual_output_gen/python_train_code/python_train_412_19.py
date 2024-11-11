a = []
for i in range(6):
    a.append(int(input()))
a1 = a[0]
a2 = min(a[1], a[2])
a3 = a[3]
b1 = min(a1, a3)
b2 = min(a2, a3)
cost = 0
for i in range(b1):
    cur = i*a[4] + (min(a[3]-i, b2))*a[5]
    if cost < cur:
        cost = cur
print(cost)
    

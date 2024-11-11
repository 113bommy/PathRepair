a = [int(i) for i in input().split(" ")]
x = a[0]
y = a[1]
y = 240 - y
t = 0
while t <= x:
    if t * 5 <= y:
        y = y - (t * 5)
        t = t + 1
    else:
        break
t = t-1
print(t)
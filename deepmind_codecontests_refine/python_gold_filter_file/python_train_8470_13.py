y = int(input())
for i in range(y + 1, 9100):
    a = set()
    t = i
    for j in range(4):
        b=i%10
        a.add(b)
        i //= 10
    if len(a) > 3:
        print(t)
        break
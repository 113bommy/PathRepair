n, d = map(int, input().split())

a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

a = list(map(lambda x: x - a[0], a))
b = list(map(lambda x: x - b[0], b))

isTrue = False
for i in range(n + 1):
    if a == b:
        isTrue = True
        break
    else:
        k = b.pop(0)
        t = b[0]
        b = list(map(lambda x: x - b[0], b))
        b.append(k + t)

if isTrue:
    print("YES")
else:
    print("NO")
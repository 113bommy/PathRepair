m = int(input())
k = 0

f = False
fs = []
for i in range(1, 10000):
    z = sum(i // 5**u for u in range(1, 10))
    if z == m:
        f = True
        fs.append(i)
    if z > m:
        break
if f:
    print(len(fs))
    for i in fs[:-1]:
        print(i, end=' ')
    print(fs[-1])
else:
    print(0)

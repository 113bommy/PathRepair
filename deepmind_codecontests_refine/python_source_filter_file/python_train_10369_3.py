x, y, l, r = map(int, input().split())

xs = [1]
ys = [1]

while xs[-1]*x <= r:
    xs.append(xs[-1]*x)

while ys[-1]*y <= r:
    ys.append(ys[-1]*y)

zs = [x+y for x in xs for y in ys]
zs.extend([l-1, r+1])
zs.sort()

zs = list(filter(lambda z: z <= r and z >= l, zs))

print(max([zs[i+1]-zs[i]-1 for i in range(len(zs)-1)]))
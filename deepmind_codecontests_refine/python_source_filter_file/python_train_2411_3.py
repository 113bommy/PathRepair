lines = set()
points = []
num = int(input())
for i in range(num):
    points.append([int(j) for j in input().split()])
for i in range(num):
    for j in range(i):
        dx = (points[j][0] - points[i][0])
        if dx == 0:
            lines.add((3785961, points[i][0]))
        else:
            m = (points[j][1] - points[i][1])/dx
            lines.add((int(1000000*m), int(1000000*(points[i][1] - m * points[i][0]))))
ms = {}
for l in lines:
    if l[0] in ms:
        ms[l[0]] += 1
    else:
        ms[l[0]] = 1

total = 0
#print(lines)
#print(ms)
#print(type(ms.values()))
t = list(ms.values())

s = sum(t)

for a in t:
    total += a * (s-a)
print(total//2)

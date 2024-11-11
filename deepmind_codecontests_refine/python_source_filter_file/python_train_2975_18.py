l1 = []
for i in range(3):
    l1.append([int(s) for s in input().split()])
x1 = l1[2][0] - l1[0][0] + l1[1][0]
y1 = l1[2][1] - l1[0][1] + l1[1][1]
x2 = l1[2][0] - l1[1][0] + l1[0][0]
y2 = l1[2][1] - l1[1][1] + l1[0][1]
x3 = -1*l1[2][0] + l1[0][0] + l1[1][0]
y3 = -1*l1[2][1] + l1[0][1] + l1[1][1]
print(x1,y1)
print(x2,y2)
print(x3,y3)
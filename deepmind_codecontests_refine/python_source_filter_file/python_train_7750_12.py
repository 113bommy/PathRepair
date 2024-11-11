b_data = [int(bd) for bd in input().split()]
options, money = b_data[0], b_data[1]
types = []
maxy = -1
for o in range(options):
    types.append([int(x) for x in input().split()])
for t in types:
    if t[0] < money and t[1] > 0:
        maxy = max(maxy, 100 - t[1])
    elif t[0] < money and t[1] == 0:
        maxy = max(maxy,0)
print(maxy)
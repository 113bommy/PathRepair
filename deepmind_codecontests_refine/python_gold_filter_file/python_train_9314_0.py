num_coor = input().split()
num_storm = int(num_coor[0])
han_coor = [int(num_coor[1]), int(num_coor[2])]
l = []
for i in range(num_storm):
    temp = tuple([int(h) for h in input().split()])
    l.append(temp)
for f in range(len(l)):
    temp = l[f]
    if temp[0] == han_coor[0]:
        l[f] = "banana"
    else:
        slope = ((temp[1] - han_coor[1]) / (temp[0] - han_coor[0]))
        l[f] = float(slope)
num = set(l)
print(len(num))
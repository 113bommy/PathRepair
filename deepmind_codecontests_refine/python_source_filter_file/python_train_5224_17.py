n = int(input())
room = [(0) for x in range(10)]
s = [x for x in input()]
for l in s:
    if l == 'L':
        room[room.index(0)] = 1
    elif l == 'R':
        room[9-room.index(0)] = 1
    else :
        room[int(l)] = 0
k = ''
for x in room:
    k = k + str(x)
print(k)
#!/usr/bin/pthon3

n = int(input())
ins = str(input())

pos = [(0, 0)]*n

for i in range(n):
    if ins[i] == 'U':
        if i == 0:
            pos[i] = (0,1)
        else:
            pos[i] = (pos[i-1][0], pos[i-1][1]+1)
    elif ins[i] == 'L':
        if i == 0:
            pos[i] = (-1,0)
        else:
            pos[i] = (pos[i-1][0]-1, pos[i-1][1])
    elif ins[i] == 'R':
        if i == 0:
            pos[i] = (1,0)
        else:
            pos[i] = (pos[i-1][0]+1, pos[i-1][1])
    elif ins[i] == 'D':
        if i == 0:
            pos[i] = (0,-1)
        else:
            pos[i] = (pos[i-1][0], pos[i-1][1]-1)

ans = 0
d = dict()
d[(0,0)] = 1
print(pos)
for i in pos:
    if i in d:
        ans += d[i]
        d[i] += 1
    else:
        d[i] = 1

print(str(ans))

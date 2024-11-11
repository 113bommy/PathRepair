#!/usr/bin/env python3

n = int(input())
h = [int(i) for i in input().split(' ')]

mini = h[0]
maxi = h[0]
group = [[mini,maxi]]
for i in range(n):
    if h[i]<group[-1][1]:
        group[-1][0] = h[i]
        while len(group)>2 and group[-1][0]<=group[-2][1]:
            group[-1][1] = max(group[-1][1],group[-2][1])
            group.pop(-2)
    elif h[i]>=group[-1][1]:
        group.append([h[i],h[i]])
print(len(group)-1)

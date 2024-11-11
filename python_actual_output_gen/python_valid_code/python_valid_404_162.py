#!/usr/bin/python3

n = int(input())
rooms = []
count = 0

for i in range(n):
    rooms.append(list(map(int, input().split())))
for i in range(n):
    if (rooms[i][1] - rooms[i][0]) > 2:
        count += 1
print(count)

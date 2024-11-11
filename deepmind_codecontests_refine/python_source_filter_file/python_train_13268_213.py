n = int(input())
rooms = []
room_count = 0

while n > 0:
    rooms.append([int(x) for x in input().split()])
    n -= 1

for i in range(len(rooms)):
    if rooms[i][1] - rooms[i][0]:
        room_count += 1
    

print(room_count)
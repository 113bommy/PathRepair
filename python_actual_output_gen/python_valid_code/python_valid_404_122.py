rooms = int(input())
accommodates = 0

for room in range(rooms):

    info = [int(r) for r in input().split()]

    if info[0] < info[1]:
        accommodates += 1

print(accommodates)
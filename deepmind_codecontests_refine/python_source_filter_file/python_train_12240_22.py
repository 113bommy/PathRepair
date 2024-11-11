import math
info = [int(x) for x in input().split()]
lanes = info[0]
desks = info[1]
location = info[2]
seats_in_lane = 2 * desks
lane = math.ceil(location/seats_in_lane)
starting_group = ((lane-1) * seats_in_lane) + 1
# print(starting_group)
desk = math.ceil((location - starting_group + 1)/2)
l_r = "R" if desk % 2 == 0 else "L"
print(lane,desk,l_r)

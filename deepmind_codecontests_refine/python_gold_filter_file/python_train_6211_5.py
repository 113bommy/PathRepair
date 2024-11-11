import re

n = int(input())
ships = {}
lst = []
r = re.compile('\((\d+)\+(\d+)\)\/(\d+)')

for i in range(n):
    line = input()    
    m = r.match(line)
    coord = (int(m.group(1)) + int(m.group(2)))/int(m.group(3))
    ships[coord] = ships.get(coord, 0) + 1
    lst.append(coord)
    
for k in lst:
    print(ships[k])
    pass

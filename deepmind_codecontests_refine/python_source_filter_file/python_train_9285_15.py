n = int(input())
sticks = [int(i) for i in input().split()]

sticks.sort()

p1 = 0
p2 = n -1
coord = [0, 0]
while True:
    if p2 < p1: break
    if p1 == p2:
        coord[0] += sticks[p1]
        break    
    coord[0] += sticks[p2]
    coord[1] += sticks[p1]
    p1 += 1
    p2 -= 2

square = coord[1] ** 2 + coord[0] ** 2

print(square)
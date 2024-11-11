n, v = map(int, input().split())

distance = n - 1

if v>=distance:
    print(distance)
else:
    cost = v
    for i in range(2, distance - v + 1):
        cost += 1
    print(cost)
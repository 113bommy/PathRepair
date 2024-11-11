n = int(input())
count = 0
points = [tuple(map(int, input().split())), tuple(map(int, input().split()))]
for i in range(2, n + 1):
    x, y = map(int, input().split())
    points.append((x, y))
    if points[i - 1][0] < x:
        temp = 'east'
    if points[i - 1][0] > x:
        temp = 'west'
    if points[i - 1][1] < y:
        temp = 'north'
    if points[i - 1][1] > y:
        temp = 'south'
    x = points[i - 1][0]
    y = points[i - 1][1]
    if points[i - 2][0] < x:
        temp1 = 'east'
    if points[i - 2][0] > x:
        temp1 = 'west'
    if points[i - 2][1] < y:
        temp1 = 'north'
    if points[i - 2][1] > y:
        temp1 = 'south'
    if (temp1, temp) in [('north', 'west'), ('west', 'north'), ('south', 'east'), ('east', 'north')]:
        count += 1
print(count)
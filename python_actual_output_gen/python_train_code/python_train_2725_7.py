n = int(input())
points = []
for i in range(n):
    points.append(list(map(int, input().split())))

count = 0
for i in range(n):
    x, y = points[i]
    up, down, left, right = False, False, False, False
    for j in range(n):
        x2, y2 = points[j]
        if x == x2:
            if y < y2:
                up = True
            elif y > y2:
                down = True
        elif y == y2:
            if x < x2:
                right = True
            elif x > x2:
                left = True
    if up == down == left == right: count += 1

print(count)



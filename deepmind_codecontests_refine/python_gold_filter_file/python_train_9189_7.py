t = int(input())
for tc in range(t):
    line = input().split()
    x1, y1, x2, y2 = int(line[0]), int(line[1]), int(line[2]), int(line[3]) 
    if x1 == x2:
        print(abs(y1-y2))
    elif y1 == y2:
        print(abs(x1-x2))
    else:
        ans = (abs(x1-x2)) + (2 + abs(y1-y2))
        print(ans)
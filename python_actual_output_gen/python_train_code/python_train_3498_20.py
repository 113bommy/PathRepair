p, y = (int(x) for x in input().split())
while y > p:
    bound = min(p, int(y ** 0.5) + 1)
    fl = False
    for div in range(1, bound + 1):
        if y % div == 0:
            fl = True
            break
    if not fl:
        print(y)
        quit()
    y -= 1
print(-1)
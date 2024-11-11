M,D=map(int,input().split())
count = 0
for d in range(22,D):
    d1 = d % 10
    d2 = (d - d % 10)/10
    if d1 < 2 or d2 < 2:continue
    elif d1 * d2 <= M:
        count += 1
print(count)
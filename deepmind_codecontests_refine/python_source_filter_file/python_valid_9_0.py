#codeforces round 734 B1
tests = int(input())
arr = []
out = []

for _ in range(tests):
    arr.append(input())

for x in range(len(arr)):
    used = []
    used2 = []
    r = 0
    g = 0
    for y in range(len(arr[x])):
        if arr[x][y] not in used and r < len(arr[x])//2 + 1:
            used.append(arr[x][y])
            r += 1
        elif arr[x][y] not in used2:
            used2.append(arr[x][y])
            g += 1
    #print(r, g)
    if abs(r-g) > 1:
        out.append((r+g)//2)
    elif r > g:
        out.append(r-1)
    else:
        out.append(r)

for a in out:
    print(a)


        
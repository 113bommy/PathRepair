l, step = [int(i) for i in input().split(" ")]
line = input()


gIndex = line.index('G')
tIndex = line.index('T')


found = False
if gIndex > tIndex:
    for i in range(gIndex, tIndex-1, -step):
        if i == tIndex:
            print("YES")
            found = True
            break
        elif line[i] == '#':
            print("NO")
            found = True
            break
else:
    for i in range(gIndex, tIndex-1, -step):
        if i == tIndex:
            print("YES")
            found = True
            break
        elif line[i] == '#':
            found = True
            print("NO")
            break

if not found:
    print("NO")

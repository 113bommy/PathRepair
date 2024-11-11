a, b = list(map(int, input().split()))
bulb = [int(x) for x in range(1, b+1)]
for i in range(a):
    bulblist = [int(x) for x in input().split()]
    for j in bulblist[1:]:
        if bulb.count(j) > 0:
            bulb.remove(j)
    if not bulb:
        break
print(["YES", "NO"][bulb != []])

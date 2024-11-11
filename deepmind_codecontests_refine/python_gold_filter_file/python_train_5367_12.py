number = [int(c) for c in input().split(" ")]
it = 1
vershini = [-1]
skladi = []    
minimum = []
while it <= number[0]:
    vershini.append([])
    it += 1
it = 1
while it <= number[1]:
    a,b,c = [int(c) for c in input().split(" ")]
    vershini[a].append((b,c))
    vershini[b].append((a,c))
    it += 1
it = 1
while it < len(vershini):
    vershini[it].sort(key = lambda vsh: vsh[1])
    it += 1
if number[2] != 0:
    skladi = [int(c) for c in input().split(" ")]
if len(skladi) < number[0] - len(skladi):
    for ab in skladi:
        it = 0
        while it < len(vershini[ab]):
            if not vershini[ab][it][0] in skladi:
                minimum.append(vershini[ab][it][1])
                break
            it += 1
else:
    it = 1
    vse = set(range(1,number[0]+1))
    goroda = list(vse-set(skladi))
    for ab in goroda:
        it = 0
        while it < len(vershini[ab]):
            if not vershini[ab][it][0] in goroda:
                minimum.append(vershini[ab][it][1])
                break
            it += 1
if skladi != 0 and len(minimum) != 0:
    minimum.sort()
    print(minimum[0])
else:print(-1)
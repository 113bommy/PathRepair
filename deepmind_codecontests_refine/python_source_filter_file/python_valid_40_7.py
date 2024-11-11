n = int(input())
for i in range(n):
    l1 = []
    l2 = []
    m = int(input())
    g1 = input()
    g1 = g1.split()
    g2 = input()
    g2 = g2.split()
    for o in g1:
        l1.append(int(o))
    for o in g2:
        l2.append(int(o))


    s = sum(l1)
    z1 = sum(l1) - l1[0]
    z2 = 0
    zaehler = -1
    speicher = 10000000
    speicher2 = 10000000
    for x in range(len(l1) - 1):
        z1 -= l1[x + 1]
        z2 += l2[x]
        if max(z1, z2) < speicher:
            speicher = max(z1, z2)
        if max(z1, z2) > speicher2:
            break
        speicher2 = speicher

    if speicher == 100000:
        speicher = 0
    elif speicher > sum(l1) - l1[0]:
        speicher = sum(l1) - l1[0]
    print(speicher)
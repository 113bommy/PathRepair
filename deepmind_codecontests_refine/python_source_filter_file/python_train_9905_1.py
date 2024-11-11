n = int(input()) // 2
c = map(int, list(input()))
a = map(int, list(input()))

artists = zip(c, a)

both, none, clowns, acrobats = [], [], [], []

for i, artist in enumerate(artists):
    if sum(artist) == 2:
        both.append(i + 1)
    elif sum(artist) == 0:
        none.append(i + 1)
    elif artist[0] == 1:
        clowns.append(i + 1)
    else:
        acrobats.append(i + 1)

success = False
for z1 in range(len(none) + 1):
    b1 = len(acrobats) + len(both) - n + z1
    if not 0 <= b1 <= len(both):
        continue
    if success:
        break

    for a1 in range(len(acrobats) + 1):
        c1 = n - z1 - b1
        if not 0 <= c1 <= len(clowns):
            continue

        if a1 + b1 + c1 + z1 == n:
            first = []
            for i in range(z1):
                first.append(none[i])
            for i in range(b1):
                first.append(both[i])
            for i in range(a1):
                first.append(acrobats[i])
            for i in range(c1):
                first.append(clowns[i])
            success = True
            print(*first)
            break

if not success:
    print(-1)
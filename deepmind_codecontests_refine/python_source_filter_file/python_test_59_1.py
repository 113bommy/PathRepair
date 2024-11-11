t = int(input())

for test_case in range(t):
    n = int(input())

    pairs = []
    for a in range(5):
        for b in range(a, 5):
            pairs.append((a,b))

    tallies = []
    for c in range(10):
        tallies.append([[0,0],[0,0]])

    for i in range(n):
        line = str(input()).split()
        line = list(map(int, line))
        for c in range(10):
            p = pairs[c]
            i, j = p[0], p[1]
            x, y = line[i], line[j]
            tallies[c][x][y] += 1

    flag = False
    half = n/2
    for c in range(10):
        tally = tallies[c]
        if tally[0][0] == 0 and tally[0][1] <= half and tally[1][0] <= half:
            flag = True
            break

    if flag:
        print("YES")
    else:
        print("NO")

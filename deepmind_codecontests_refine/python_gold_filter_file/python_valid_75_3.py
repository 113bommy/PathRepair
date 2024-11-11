t = int(input().strip())

for _ in range(t):
    n = int(input().strip())
    levels = []
    for i in range(n):
        level = list(map(int, input().strip().split()))
        maxi = level[1] + 1
        index = 0
        for i,e in enumerate(level[1:]):
            if e - i + 1 > maxi:
                maxi = e - i + 1
                index = i
        d = [maxi, level[0]]
        levels.append(d)

    levels.sort(key=lambda x:x[0])
    mini = levels[0][0]
    monsters = 0
    for l in levels:
        mini = max(mini, l[0]-monsters)
        monsters += l[1]

    print(mini)
insc = {
    (1, 2): 3,
    (1, 3): 4,
    (2, 1): 3,
    (2, 3): float("inf"),
    (3, 1): 4,
    (3, 2): float("inf")
}

n = int(input())

figures = [int(i) for i in input().split()]

resp = 0

for i in range(1, len(figures)):
    fig = figures[i]
    figAnt = figures[i-1]

    resp += insc[(fig, figAnt)]

    try:
        if fig == 2 and figAnt == 1 and figures[i-2] == 3:
            resp += 1
    except:
        continue

if resp == float("inf"):
    print("Infinite")
else:
    print("Finite")
    print(resp)

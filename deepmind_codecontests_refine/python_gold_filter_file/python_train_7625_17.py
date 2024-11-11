t = int(input())
for _ in range(t):
    rock, paper, scissors = 0, 0, 0
    line = input()
    for i in line:
        if i == "R":
            rock += 1
        elif i == "P":
            paper += 1
        else:
            scissors += 1
    n = len(line)
    if rock >= paper and rock >= scissors:
        print(n * "P")
    elif paper >= rock and paper >= scissors:
        print(n * "S")
    else:
        print(n * "R")
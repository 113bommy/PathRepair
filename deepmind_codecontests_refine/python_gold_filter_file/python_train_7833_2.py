cases = []
for i in range(int(input())):
    input()
    cases.append([list(input()), list(input())])

def solve(case):
    a=case[0]
    b=case[1]
    ab=[list(pair) for pair in zip(a, b) if pair[0] != pair[1]]
    ab.sort()
    for pair in ab:
        if pair[0] > pair[1]:
            print("-1")
            return
    moves = 0
    while len(ab) > 0:
        moves += 1
        lowest_b = ab[0][1]
        s = 0
        for i in ab:
            if i[0] != ab[0][0]:
                break
            lowest_b = min(lowest_b, i[1])
            s += 1

        sli = [[lowest_b, p[1]] for p in ab[:s]]
        ab[:s] = sli
        #print("\n".join(map("".join, list(zip(*ab)))))

        ab = sorted([pair for pair in ab if pair[0] != pair[1]])
    print(moves)

for case in cases:
    solve(case)


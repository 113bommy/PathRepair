t = int(input())
cases = []
for i in range(t):
    n = int(input())
    cases.append(list(map(int, input().strip().split())))

def solve(case):
    nonfixed = []
    for i, n in enumerate(case):
        if i != n:
            nonfixed.append(i)
    if len(nonfixed) == 0:
        print("0")
        print("")
        return

    steps = 0
    outst = ""
    while len(nonfixed) > 0:
        steps += 1
        mex = set(range(len(case)+1))
        for n in case:
            if n in mex:
                mex.remove(n)
        mex = min(mex)

        if mex == len(case):
            case[nonfixed[0]] = mex
            outst += str(nonfixed[0]) + " "
        else:
            case[mex] = mex
            outst += str(mex) + " "
            nonfixed.remove(mex)

    print(steps)
    print(outst)

for case in cases:
    solve(case)

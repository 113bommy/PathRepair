def makeOutput(alems, nelem):
    orig = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
    es = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    cur = orig
    print(cur)
    for chg in alems:
        if cur[chg - 1] == "z":
            cur = cur[0:chg]
            cur += es
        else:
            cur = cur[0:chg]
            cur += orig
        print(cur)

numTestCases = int(input())
for _ in range(numTestCases):
    numelements = int(input())
    aelems = input()
    aelems = aelems.split()
    aelems = list(map(int, aelems))
    makeOutput(aelems, numelements)
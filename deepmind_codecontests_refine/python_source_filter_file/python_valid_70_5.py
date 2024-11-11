import math

def solve(s):
    letters = {}
    uniques = []
    for i in range(len(s)):
        ref = len(s)-1-i
        if(uniques.count(s[ref])==0):
            uniques.append(s[ref])
            letters[s[ref]] = 1
        else:
            letters[s[ref]] += 1
    tot = 0
    removed = ''
    for i in range(len(uniques)):
        ref = len(uniques)-1-i
        removed = removed + uniques[ref]
        letters[uniques[ref]] = int(letters[uniques[ref]]/(ref+1))
        tot += letters[uniques[ref]]

    init = s[:tot]

    init2 = init
    test = ''
    for i in range(len(removed)):
        test += init2
        init2 = init2.replace(removed[i],'')

    if test==s:
        print(init,removed)
    else:
        print(-1)

tot = int(input())
for i in range(tot):
    solve(input())
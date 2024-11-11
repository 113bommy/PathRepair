T = input()
for t in range(int(T)):
    S = input()
    maxOccurrence = 0
    myChoices = ''
    rCount = S.count('R')
    sCount = S.count('S')
    pCount = S.count('P')
    if rCount >= sCount and rCount >= pCount:
        maxOccurrence = 'R'
    elif sCount >= rCount and sCount >= pCount:
        maxOccurrence = 'S'
    else:
        maxOccurrence = 'P'

    if maxOccurrence == 'R':
        myChoices = 'P' * len(S)
    elif maxOccurrence == 'S':
        myChoices = 'R' * len(S)
    else:
        myChoices = 'S' * len(S)

    print(myChoices)



def Winner(wins, A):
    winStack = []
    loseStack = []
    count = 0

    if wins > 1000:
        wins = 1000
        
    if A[0] > A[1]:
        winStack.append(A[0])
        loseStack.append(A[1])
        count += 1
    else:
        winStack.append(A[1])
        loseStack.append(A[0])
        count += 1

    index = 2
    while index < len(A):
        if winStack[-1] > A[index]:
            count += 1
            if count == wins:
                return winStack[-1]
        else:
            loseStack.append(winStack.pop())
            winStack.append(A[index])
            count = 0
        index += 1

    while count != wins:
        for x in loseStack:
            if winStack[-1] > x:
                count += 1
                return winStack[-1]
            else:
                lost = winStack.pop()
                loseStack.append(lost)
                winStack.append(x)
                count = 0

numPlayers, wins = input().split()
numPlayers = int(numPlayers)
wins = int(wins)
powerPlayers = list(map(int, input().split()))

print(Winner(wins, powerPlayers))

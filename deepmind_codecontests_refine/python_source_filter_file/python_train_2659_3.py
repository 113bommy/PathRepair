def getMinimumPossibleWidth(fenceHeight, friends):
    width = 0
    for i in range(len(friends)):
        if friends[i] > fenceHeight:
            width += 2
        else:
            width += 1

    return width


if __name__ == "main":
    nH = list(map(int, input().rstrip().split()))
    friends = list(map(int, input().rstrip().split()))

    print(getMinimumPossibleWidth(nH[1], friends))
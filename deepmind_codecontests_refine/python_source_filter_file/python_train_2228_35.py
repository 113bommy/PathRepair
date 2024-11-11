studentNum, puzzleNum = map(int, input().split())

puzzleList = list(map(int, input().split()))

puzzleList.sort()

result = puzzleList[studentNum - 1] - puzzleList[0]

for i in range(1, len(puzzleList) - studentNum):
    a = puzzleList[i]
    b = puzzleList[i + studentNum - 1]

    if b - a < result:
        result = b - a

print(result)

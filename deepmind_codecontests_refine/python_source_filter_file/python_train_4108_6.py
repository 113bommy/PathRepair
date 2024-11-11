n = int(input())
a = sorted([int(x) for x in input().split()])

occurrences = {}

for i in a:
    if i in occurrences:
        occurrences[i] += 1
    else:
        occurrences[i] = 1

scores = {i: i * occurrences[i] for i in a}

scoresList = [scores.get(i, 0) for i in range(1, 100001)]

cumulativeScore = 0
previousCumulativeScore = -1000000
for i in scoresList:
    buffer = cumulativeScore
    cumulativeScore = max(cumulativeScore, previousCumulativeScore + i)
    previousCumulativeScore = buffer

print(cumulativeScore)
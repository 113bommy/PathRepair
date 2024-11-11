# B427. Prison Transfer

prisonNum, crimeStd, chooseNum = map(int, input().split())

crimeLv = list(map(int, input().split()))

# Let's split
newList = []
prev = 0

for i in range(prisonNum):
    if crimeLv[i] > crimeStd:
        if prev == i:
            prev = i + 1
        else:
            newList.append(crimeLv[prev:i])
            prev = i + 1
            i += 1
if prev < prisonNum-1:
    newList.append(crimeLv[prev:prisonNum])

# Let's count
count = 0

for crimeList in newList:
    if len(crimeList) < chooseNum:
        continue
    elif len(crimeList) == chooseNum:
        count += 1
        continue
    else:
        count += (len(crimeList) - chooseNum + 1)

print(count)

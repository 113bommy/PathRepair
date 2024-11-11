n = int(input())
l = list(map(int, input().split()))

d = dict()

summ = sum(l)
for i in range(n):
    if l[i] in d:
        d[l[i]].append(i)
    else:
        d[l[i]] = []
        d[l[i]].append(i)

kList = list(d.keys())
kList.sort(reverse = True)

resList = []
count = 0
for x in kList:
    if count > 1:
        break
    count = count + 1

    tmpSum = summ - x

    if count == 1:
        if len(d[x]) == 2:
            if (tmpSum - x) in d:
                resList = resList + d[x]

        if len(d[x]) == 3 and len(kList) == 1:
            resList = resList + d[x]

        for i in range(1, len(kList)):
            tmpSum2 = int(tmpSum - kList[i])
            if tmpSum2 == x:
                resList = resList + d[kList[i]]
                break

            if tmpSum2 > x:
                break

    if count == 2:
        if tmpSum - kList[0] == x:
            resList = resList + d[kList[0]]

print(len(resList))
for x in resList:
    print(x + 1, end=' ')
# Fast IO (only use in integer input)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n,h,m,k = map(int,input().split())
trainMod = []
for i in range(n):
    hi,mi = map(int,input().split())
    trainMod.append((mi % (m//2),i+1))
    if (mi % (m//2)) <= k:
        trainMod.append((mi % (m//2) + m//2,i+1))
trainMod.sort(key = lambda x: x[0])
leftIndex = 0
minCancelledTrain = n
startTime = 0
cancelLeft = 0
cancelRight = n
for i in range(len(trainMod)):
    if trainMod[i][0] < k:
        continue
    while trainMod[leftIndex][0] <= trainMod[i][0] - k:
        leftIndex += 1
    if minCancelledTrain > i - leftIndex:
        minCancelledTrain = i - leftIndex
        startTime = (trainMod[i][0] - k) % (m//2)
        cancelLeft = leftIndex
        cancelRight = i
print(str(minCancelledTrain) + ' ' + str(startTime))
cancelTrain = []
for i in range(cancelLeft,cancelRight):
    cancelTrain.append(str(trainMod[i][1]))
print(' '.join(cancelTrain))

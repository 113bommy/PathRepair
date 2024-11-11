def f(l, k):
    maxPeakCount = 0
    maxPeakLeftIndex = 0
    leftIndex = 0
    rightIndex = leftIndex + k - 1
    currPeakCount = 0
    peakSet = set()

    index = leftIndex + 1

    while index < len(l):
        if index >= rightIndex:
            #print(leftIndex, rightIndex, currPeakCount)

            if currPeakCount > maxPeakCount:
                maxPeakCount = currPeakCount
                maxPeakLeftIndex = leftIndex

            if index == len(l) - 1:
                break
            leftIndex += 1
            rightIndex += 1
            if leftIndex in peakSet:
                currPeakCount -= 1

        if l[index] > l[index + 1] and l[index] > l[index - 1]:
            currPeakCount += 1
            peakSet.add(index)

        index += 1
    return maxPeakCount + 1, maxPeakLeftIndex + 1


t = int(input())
for _ in range(t):
    _, k = tuple(map(int, input().split()))
    l = list(map(int, input().split()))
    res = f(l, k)
    print(res[0], res[1])

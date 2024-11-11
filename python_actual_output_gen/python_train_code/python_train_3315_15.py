n = int(input())
arr = [int(i) for i in input().split()]
d = {}
evCount, evIdx, odIdx, odCount = 0, -1, -1, 0
for i in range(n):
    if(i%2 == 0):
        evCount += 1
        evIdx = i + 1
    else:
        odCount += 1
        odIdx = i + 1
if(evCount > odCount):
    print(odIdx)
else:
    print(evIdx)
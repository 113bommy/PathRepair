inf = 1234567890
minR1 = minR2 = inf
maxL1 = maxL2 = -inf
for i in range(int(input())):
    l,r = map(int,input().split())
    maxL1 = max(maxL1,l)
    minR1 = min(minR1,r)
for i in range(int(input())):
    l,r = map(int,input().split())
    maxL2 = max(maxL1,l)
    minR2 = min(minR1,r)
maxRes = max(maxL1-minR2,maxL2-minR1)
maxRes = max(maxRes,0)
print(maxRes)
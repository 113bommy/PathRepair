
n = int(input())
arr = map(int, input().split())

div = int(n / 2 + 0.5)
cntPos = 0
cntNeg = 0
for i in arr:
    if i > 0:
        cntPos += 1
    else:
        cntNeg += 1
if cntPos >= div:
    print(1)
elif cntNeg >= div:
    print(-1)
else:
    print(0)

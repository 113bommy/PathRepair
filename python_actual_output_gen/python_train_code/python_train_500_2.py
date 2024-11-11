a,b = map(int, input().strip().split())
aCount = 0
bCount = 0
dasha = 0
masha = 0
curTime = 0
while 1:
    if (aCount+1) * a < (bCount+1) *b:
        aCount += 1
        dasha += aCount *a - curTime
        curTime = aCount * a
    elif (aCount+1) * a > (bCount+1) *b:
        bCount += 1
        masha += bCount *b - curTime
        curTime = bCount * b
    else:
        if a == min(a,b):
            aCount += 1
            dasha += aCount *a - curTime
            curTime = aCount * a
        else:
            bCount += 1
            masha += bCount *b - curTime
            curTime = bCount * b
        break
if masha > dasha:
    print('Masha')
elif masha < dasha:
    print('Dasha')
else:
    print('Equal')
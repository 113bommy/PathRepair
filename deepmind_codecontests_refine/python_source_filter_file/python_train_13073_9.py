n = int(input())
sher = str(input())
mor = str(input())

sherd = [0,0,0,0,0,0,0,0,0,0]
mord = [0,0,0,0,0,0,0,0,0,0]

sherd2 = [0,0,0,0,0,0,0,0,0,0]
mord2 = [0,0,0,0,0,0,0,0,0,0]

for i in range(n):
    if sher[i] == '':
        continue
    s = int(sher[i])
    sherd[s] += 1
    m = int(mor[i])
    mord[m] += 1

for i in range(10):
    sherd2[i] = sherd[i]
    mord2[i] = mord[i]

mins = 0
maxs = 0

for j in range(10):
    i = 9 - j
    diff = sherd[i] - mord[i]
    if diff > 0:
        mins += diff
    elif i > 0:
        mord[i-1] += -diff

print(mord2)
print(sherd2)

for j in range(9):
    i = 9 - j
    diff = mord2[i] - sherd2[i-1]
    if diff > 0:
        maxs += sherd2[i-1]
        if i > 0:
            mord2[i-1] += diff
    else:
        maxs += mord2[i]

print(mins)
print(maxs)
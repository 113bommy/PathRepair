X = list(map(int, input().split()))
XTotal, YTotal = X[-2] - X[1], X[-1] - X[2]
S, Cnt = input(), 0
for i in S:
    if XTotal == 0 and YTotal == 0:
        print(Cnt)
        exit()
    if i in 'EW':
        if XTotal > 0 and i == 'E': XTotal -= 1
        if XTotal < 0 and i == 'W': XTotal += 1
    else:
        if YTotal > 0 and i == 'N': YTotal -= 1
        if YTotal < 0 and i == 'S': YTotal += 1
    Cnt += 1
    if XTotal == 0 and YTotal == 0:
        print(Cnt)
        exit()
print(-1)
# Let's see who is the best !!!
# ravenS_The_Best

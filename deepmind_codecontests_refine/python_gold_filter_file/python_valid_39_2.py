import sys
input = sys.stdin.readline
t = int(input())

for test in range(t):
    wr,hr = map(int,input().split())
    x1,y1,x2,y2 = map(int,input().split())
    wt,ht = map(int,input().split())
    wot = abs(x1 - x2)
    hot = abs(y1 - y2)
    bestdist = wr+hr
    if wot + wt > wr and hot + ht > hr:
        print(-1)
    else:
        if not wot + wt > wr:
            bestdist = min(wt - x1, bestdist)
            bestdist = min(x2 - (wr - wt), bestdist)
        if not hot + ht > hr:
            bestdist = min(ht - y1, bestdist)
            bestdist = min(y2 - (hr - ht), bestdist)
        print(max(0,bestdist))
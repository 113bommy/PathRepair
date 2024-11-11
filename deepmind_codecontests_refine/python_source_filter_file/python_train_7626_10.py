#Problem B
#map(int,i().split())
import sys
def i():
    return sys.stdin.readline()[:-1]

cases = int(i())

for x in range(cases):
    p,f = map(int,i().split())
    cs,cw = map(int,i().split())
    s,w = map(int,i().split())
    if s > w:
        s,w = w,s
        cs,cw = cw,cs
    pMax = p//s
    fMax = f//s
    if pMax + fMax <= cs:
        print(pMax+fMax)
    else:
        currTotal = 0
        for y in range(cs):
            pHold = p - y*s
            fHold = f - (cs-y)*s
            if pHold >= 0 and fHold >= 0:
                currTotal = max(currTotal, min(cw,(pHold//w)+(fHold//w)))
        print(cs+currTotal)

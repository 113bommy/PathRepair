#/usr/bin/env python3

import sys

def tram(inp):
    inp = list(map(int, inp.split()))
    s = inp[0]
    x1 = inp[1]
    x2 = inp[2]
    t1 = inp[3]
    t2 = inp[4]
    p = inp[5]
    d = inp[6]

    if d < 0:
        x1 = s-x1
        x2 = s-x2
        p = s - p

    walktime = abs(x1-x2)*t2

    if (x2 > x1):
        if (p > x1):
            tramtime = (s-p + s + s-x2) * t1
        else:
            tramtime = (x2 - p) *t1
    else: 
        tramtime = ((s-p) + s -x2) * t1

    return min(walktime, tramtime)


    







if __name__ == "__main__":
    inp = sys.stdin.read()
    inp = inp.strip()
    print(tram(inp))


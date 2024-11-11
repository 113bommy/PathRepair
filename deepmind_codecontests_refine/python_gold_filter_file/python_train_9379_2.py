import sys
import random
import collections
import math

def overlap(a, b):
    return (max(a[0], b[0]), max(a[1], b[1]), min(a[2], b[2]), min(a[3], b[3]))

if __name__ == "__main__":
    rects = []
    n = int(sys.stdin.readline())

    for i in range(n):
        [x1, y1, x2, y2] = [int(i) for i in sys.stdin.readline().split()]
        rects.append((x1, y1, x2, y2))

    fOL = []
    bOL = []
    fOL.append(rects[0])
    bOL.append(rects[n - 1])
    for i in range(1, n):
        fOL.append(overlap(fOL[i - 1], rects[i]))
    for i in range(1, n):
        bOL.append(overlap(bOL[i - 1], rects[n - i - 1]))
    bOL = bOL[::-1]

    for i in range(n):
        if i == 0:
            currRect = bOL[1]
        elif i == n - 1:
            currRect = fOL[n - 2]
        else:
            currRect = overlap(fOL[i - 1], bOL[i + 1])
        if(currRect[0] <= currRect[2] and currRect[1] <= currRect[3]):
            print(currRect[0], currRect[1])
            break
    
        

import sys
import math
input = sys.stdin.buffer.readline

T = int(input())
for iTest in range(T):
    n = int(input())
    a = list(map(int,input().split()))
    
    currentX = 0
    currentMax = a[0]
    for i in range(1,n):
        if a[i]<currentMax:
            currentX = max(math.ceil(math.log2(currentMax-a[i]))+1,currentX)
        else:
            currentMax=a[i]
    print(currentX)
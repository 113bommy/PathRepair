#!/usr/bin/python3

n = int(input())
arr = [tuple(map(int, input().split())) for i in range(n)]
arr.sort()

mna = 1791
mxa = -1791
mnb = 1791
mxb = -1791
for i in range(n):
    mna = min(mna, arr[i][0])
    mnb = min(mnb, arr[i][1])
    mxa = max(mxa, arr[i][0])
    mxb = max(mxb, arr[i][1])

if mna == mxa or mnb == mxb:
    print(-1)
else:
    print((mxa - mna) * (mxb - mnb))

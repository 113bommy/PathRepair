# Why do we fall ? So we can learn to pick ourselves up.
t = int(input())
for _ in range(0,t):
    n = int(input())
    aa = [int(i) for i in input().split()]
    wws = [0]*101
    for i in aa:
        wws[i] += 1
    ss = 1
    for s in range(2,101):
        pp = 0
        for i in range(1,s+1):
            pp += min(wws[i],wws[s-i])
        ss = max(ss,pp//2)
    print(ss)




"""


5
5
1 2 3 4 5
8
6 6 6 6 6 6 8 8
8
1 2 2 1 2 1 1 2
3
1 3 3
6
1 1 3 4 2 2






"""

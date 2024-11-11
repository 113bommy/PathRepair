import sys
sys.setrecursionlimit(311111)
# import numpy as np
ikimasu = sys.stdin.buffer.readline
ini = lambda: int(ins())
ina = lambda: list(map(int, ikimasu().split()))
ins = lambda: ikimasu().strip()

codeforces = ini()
for _ in range(codeforces):
    n = ini()
    tmp = ina()
    rick=0
    for i in tmp:
        if(i==0):
            rick+=1

    for i in tmp:
        if(i==0):
            rick-=1
        else:
            break
    for i in range(n-1,-1,-1):
        if(tmp[i]==0):
            rick-=1
        else:
            break
    print(rick,'ans')

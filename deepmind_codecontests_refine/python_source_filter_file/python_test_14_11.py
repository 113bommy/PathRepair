from math import ceil, log, floor
from collections import defaultdict
import sys
import os.path

sys.setrecursionlimit(200000)
if (os.path.exists('input.txt')):
    sys.stdin = open("input.txt", "r+")
    sys.stdout = open("output.txt", "w")


# input = sys.stdin.readline
# print=sys.stdout.write
def MI():
    return map(int, input().split())


def solve():
    n = int(input())
    a=list(MI())

    b=sorted(a)
    l=[]
    

    for i in range(n):
        if a[i]==b[i]:
            continue
        for j in range(i+1,n):
            if a[j]==b[i]:
                break
        l.append([i+1,j+1,1])
        prev=a[j]
        for k in range(i,j+1):
            pre=a[k]
            a[k]=prev
            prev=pre 
    print(len(l))
    # print(a)
    for i in l:
        print(*i)




        

    

    



t=int(input())
for _ in range(t):
    solve()
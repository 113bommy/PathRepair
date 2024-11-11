import sys
import math
import collections
import bisect
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
for t in range(1):
    n=int(input())
    arr=dict()
    sol=[]
    done=False
    for i in range(n):
        size=int(input())
        row=get_list()
        ans=[sum(row)]*size
        if done==True:
            continue
        for j in range(size):
            ans[j]-=row[j]
        for j in range(size):
            if ans[j] not in arr:
                arr[ans[j]]=(i+1,j+1)
            else:
                if arr[ans[j]][0]==i+1:
                    continue
                sol=[arr[ans[j]],(i+1,j+1)]
                done=True
    if done==True:
        print("YES")
        print(sol[0])
        print(sol[1])
    else:
        print("NO")
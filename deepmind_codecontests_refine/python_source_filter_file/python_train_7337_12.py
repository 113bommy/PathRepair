import sys
import math
import collections
import bisect
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
for t in range(1):
    n=int(input())
    string=list(get_string())
    if len(set(string))<n:
        print("NO")
        continue
    selected=set()
    selected.add(string[0])
    ans=[]
    left=0
    counted=0
    for i in range(1,len(string)+1):
        if counted==n-1:
            sub_string=string[left:]
            ans.append(sub_string)
            break
        else:
            sub_string=string[left:i]
        if sub_string[-1] not in selected:
            selected.add(sub_string[-1])
            ans.append(sub_string[:len(sub_string)-1])
            selected.add(sub_string[0])
            left=i-1
            counted+=1
    print("YES")
    for i in ans:
        print(*i,sep="")
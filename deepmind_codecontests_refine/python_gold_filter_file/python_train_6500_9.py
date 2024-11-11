import sys
import math
import collections
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
n=int(input())
arr=get_list()
order=arr.copy()
order.sort()
val=0
prefix_val=val
prefix=[val]
sorted_prefix=[val]
for i in range(n):
    prefix.append(val+arr[i])
    val+=arr[i]
    sorted_prefix.append(prefix_val+order[i])
    prefix_val+=order[i]
for i in range(int(input())):
    m,l,r=get_ints()
    if m==1:
        print(prefix[r]-prefix[l-1])
    else:
        print(sorted_prefix[r]-sorted_prefix[l-1])
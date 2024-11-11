import math
import sys
import collections
import bisect
import time
def get_ints():return map(int, sys.stdin.readline().strip().split())
def get_list():return list(map(int, sys.stdin.readline().strip().split()))
def get_string():return sys.stdin.readline().strip()
for t in range(int(input())):
    n=int(input())
    arr=get_list()
    arr.sort()
    ans1=set()
    ans2=set()
    for i in range(n):
        ele=arr[i]
        if ele not in ans1:
            ans1.add(ele)
        else:
            ans2.add(ele)
    val=0
    for i in range(101):
        if i not in ans1:
            val+=i
            break
    for i in range(101):
        if i not in ans2:
            val+=i
            break
    print(val)
import sys
import collections
import bisect
import time
import random
from itertools import permutations
import string
import math
def get_ints():return map(int, sys.stdin.readline().strip().split())
def get_list():return list(map(int, sys.stdin.readline().strip().split()))
def get_string():return sys.stdin.readline().strip()
two=set()
for i in range(1,32):
    two.add(2**i)
for t in range(int(input())):
    n=int(input())
    arr=get_list()
    ans=[0]
    for i in range(1,n):
        prev = bin((arr[i-1] ^ ans[-1]))[2:]
        binary=bin(arr[i])[2:]
        #print(prev, binary)
        if len(prev)<len(binary):
            prev="0"*(len(binary)-len(prev))+prev
        else:
            binary="0"*(len(prev)-len(binary))+binary
        #print(prev, binary)
        #print("##")
        xor=""
        for left,right in zip(prev,binary):
            if left=="0":
                xor+="0"
            elif left==right:xor+="0"
            else:xor+="1"
        xor=int(xor,2)
        ans.append(xor)
        #print(ans)
    print(ans)
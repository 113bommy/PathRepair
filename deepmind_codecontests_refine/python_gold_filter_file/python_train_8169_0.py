import math,string,itertools,fractions,heapq,collections,re,array,bisect
from itertools import chain, dropwhile, permutations, combinations
from collections import defaultdict, deque

def VI(): return list(map(int,input().split()))

def ret_yes(x):
    print("YES")
    print(x)

def pr(a):
    print(a[0],end="")
    for x in a[1:]:
        print("->{}".format(x),end="")
    print()
def pr2(a):
    p = 0
    for i,x in enumerate(a[:-2]):
        if x==0:# and a[i+1]==1:
            print("{}->(".format(x),end="")
            p += 1
        else:
            print("{}->".format(x),end="")
    print(a[-2],end="")
    for i in range(p):
        print(")",end="")
    print("->{}".format(a[-1]))



def main(n,a):
    if a[-1] != 0:
        print("NO")
    elif n==1:
        print("YES")
        print("0")
    elif n==2 and a[0]==0:
        print("NO")
    elif a[-2]==0 and 0 not in set(a[:-2]):
        print("NO")
    elif a[-2]==1:
        print("YES")
        pr(a)
    else: # ..-> 0 -> .. 1 -> 0 -> 0 -- needs to add parentheses
        print("YES")
        pr2(a)


def main_input(info=0):
    n = int(input())
    a = VI()
    main(n,a)

if __name__ == "__main__":
    main_input()

from sys import stdin,stdout
# from collections import deque,Counter,defaultdict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce
def ii():return int(stdin.readline())
def mi():return map(int,stdin.readline().split())
def li():return list(mi())
def si():return stdin.readline()

s1 = si().rjust(10**6,'0')
s2 = si().rjust(10**6,'0')
if s1>s2:
    print('>')
elif s1<s2:
    print('<')
else:
    print('=')
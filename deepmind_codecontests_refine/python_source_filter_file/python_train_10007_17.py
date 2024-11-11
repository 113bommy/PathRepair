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

l1 = ['00:00','01:10',"02:20",'03:30','04:40','05:50','06:60','10:01','11:11','12:21','13:31','14:41','15:51','20:02','21:12','22:22','23:32']
s1 = input()
for i in l1:
    if i>s1:
        print(i)
        break
else:
    print(l1[0])
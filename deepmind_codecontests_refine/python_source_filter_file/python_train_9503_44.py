#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import Counter
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

input = sys.stdin.readline

########################################

arr = [1, 3, 40, 1260, 72576, 6652800, 889574400, 163459296000, 39520825344000, 12164510040883200, 4644631106519040000, 2154334728240414720000, 1193170003333152768000000, 777776389315596582912000000]
n = int(input())
print(n//2 - 1)



'''
# Wrap solution for more recursion depth
#submit as python3
import collections,sys,threading
sys.setrecursionlimit(10**9)
threading.stack_size(10**8)



threading.Thread(target=solve).start()
'''

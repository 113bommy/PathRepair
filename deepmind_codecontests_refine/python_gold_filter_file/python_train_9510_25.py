'''     ##     ##  #######  # #  ######
        ##     ##  ##   ##  ###    ##
        ##     ##  ##    #  # #    ##
        #########  #######  # #    ##    '''

import sys
import math
# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())

def printspx(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end=" \ ")

MODPRIME = int(1e9+7); BABYMODPR = 998244353;


# sys.stdin = open("input.txt","r")  # <<<  Comment this line  >>> #
# for _testcases_ in range(int(input())):
from collections import defaultdict
n =  int(input())
li = get_list()
d = defaultdict(lambda: [])
for i, v in enumerate(li):
    d[v].append(i)
# print(d)
for k, v in sorted(d.items()):
    if len(v) > 1:
        print("Still Rozdil")
    else:
        print(v[0] + 1)
    break

'''
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
>>> COMMENT THE STDIN !!
'''
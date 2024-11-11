import sys
def input():
    return sys.stdin.readline().strip()
 
 
def iinput():
    return int(input())
 
 
def tinput():
    return input().split()
 
 
def rinput():
    return map(int, tinput())
 
 
def rlinput():
    return list(rinput())
from collections import defaultdict
name = input()
n = iinput()
dict = defaultdict(int)

def changes(dict,name1,name2,val):
    if name1 == name:
        dict[name2] += val
    elif name2 == name:
        dict[name1] += val
    else:
        dict[name1] += 0
        dict[name2] += 0

def get_names(A):
    return A[0],A[-2][:-2]

for _ in range(n):
    A = list(input().split())
    name1,name2 = get_names(A)
    if A[1] == 'posted':
        changes(dict,name1,name2,15)
    if A[1] == 'commented':
        changes(dict,name1,name2,10)
    if A[1] == 'likes':
        changes(dict,name1,name2,5)

lists = list(dict.items())


lists.sort(key = lambda x : (-x[1],x[0]))
for l in lists:
    print(l[0])

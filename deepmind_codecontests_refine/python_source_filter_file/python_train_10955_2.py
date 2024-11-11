import os, sys, bisect, copy
from collections import defaultdict, Counter, deque
from functools import lru_cache   #use @lru_cache(None)
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
#
def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------
sys.setrecursionlimit(10**5)

from types import GeneratorType
def bootstrap(func, stack=[]):
    def wrapped_function(*args, **kwargs):
        if stack:
            return func(*args, **kwargs)
        else:
            call = func(*args, **kwargs)
            while True:
                if type(call) is GeneratorType:
                    stack.append(call)
                    call = next(call)
                else:
                    stack.pop()
                    if not stack:
                        break
                    call = stack[-1].send(call)
            return call
    return wrapped_function


n = int(input())
gr = defaultdict(list)
for i in range(n-1):
    x,y = mapi()
    gr[x].append(y)
    gr[y].append(x)

level = [0]*(n+10)
root = 1
for i in range(i,n+1):
    if len(gr[i])>1:
        root = i
        break

level[root] = 1

#levels
@bootstrap
def dfs(s,par):
    for item in gr[s]:
        if item==par: continue
        level[item] = level[s]+1
        yield dfs(item,s)
    yield
dfs(root,-1)
arr = [0]*(n+10)
odd,even = 0,0
for i in range(1,n+1):
    if len(gr[i])==1:
        if level[i]%2==0: even+=1
        else: odd+=1
        arr[i] = 1
        #print(i,odd,even)

minval,maxval = 1,n-1
if odd>0 and even>0:
    minval = 3
else: minval = 1
count = 0

@bootstrap
def rec(s,par):
    global count
    tmp =0
    for item in gr[s]:
        if item==par: continue
        if arr[item]!=0:
            tmp+=1
    if tmp>0: count+=tmp-1
    #print(s,tmp, count)
    for item in gr[s]:
        if item==par: continue
        yield rec(item,s)
    yield
rec(root,-1)
print(minval,maxval-count)
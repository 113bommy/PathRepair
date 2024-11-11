#      
import collections, atexit, math, sys, bisect 

sys.setrecursionlimit(1000000)
def getIntList():
    return list(map(int, input().split()))    

try :
    #raise ModuleNotFoundError
    import numpy
    def dprint(*args, **kwargs):
        print(*args, **kwargs, file=sys.stderr)
    dprint('debug mode')
except ModuleNotFoundError:
    def dprint(*args, **kwargs):
        pass



inId = 0
outId = 0
if inId>0:
    dprint('use input', inId)
    sys.stdin = open('input'+ str(inId) + '.txt', 'r') #标准输出重定向至文件
if outId>0:
    dprint('use output', outId)
    sys.stdout = open('stdout'+ str(outId) + '.txt', 'w') #标准输出重定向至文件
    atexit.register(lambda :sys.stdout.close())     #idle 中不会执行 atexit
    
N, K = getIntList()
 
b1 = 1
b2 = N

def spaned():
    global b1
    global b2
    b1-=K
    b2+=K
    if b1<1:
        b1 = 1
    if b2>N:
        b2 = N

import random
while True:
    while b2 - b1+1 >K*4:
        mid = (b2+b1)//2
        print(b1,mid)
        r = input()
        if r == 'Yes':
            if b1== mid:
                sys.exit()
            b2 = mid
        elif r == 'No':
            b1 =mid +1
        elif r =='Bad':
            sys.exit()
        spaned()
    t = random.randint(b1,b2)
    print(t,t)
    r = input()
    if r=='Yes':
        sys.exit()
    elif r== 'Bad':
        sys.exit()
    spaned()






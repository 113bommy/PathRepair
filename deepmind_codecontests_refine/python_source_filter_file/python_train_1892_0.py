
def naiveSolve():
    
    
    
    return

from collections import defaultdict

def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        
        # n=2000
        # m=2000
        # grid=['a'*m]*m
        
        n,m=readIntArr()
        grid=[]
        for __ in range(n):
            grid.append(input())
        ok=True
        snakes=defaultdict(lambda:[]) # {'a':[coords]}
        for i in range(n):
            for j in range(m):
                if grid[i][j]!='.':
                    snakes[grid[i][j]].append([i,j])
                    l=len(snakes[grid[i][j]])
                    if l>n or l>m: # to prevent MLE
                        ok=False
                        break
            if ok==False:
                break
        if ok==False:
            allans.append(['NO'])
            continue
        
        startEnd=dict() # {'a':[start coord, end coord]}
        # check that snake is straight
        for letter,coords in snakes.items():
            if len(coords)>=2:
                if coords[0][0]==coords[1][0]: # horizontal
                    for i in range(2,len(coords)):
                        if coords[0][0]!=coords[i][0]:
                            ok=False
                            break
                elif coords[0][1]==coords[1][1]: # vertical
                    for i in range(2,len(coords)):
                        if coords[0][1]!=coords[i][1]:
                            ok=False
                            break
                else: # diagonal. wrong
                    ok=False
            if ok==False: break
            startEnd[letter]=[coords[0],coords[-1]]
        if ok==False:
            allans.append(['NO'])
            continue
        
        # created adjacency dict for topological sort
        adj=defaultdict(lambda:[])
        for letter,[start,end] in startEnd.items():
            if start[0]==end[0]: # horizontal
                for col in range(start[1],end[1]+1):
                    letter2=grid[start[0]][col]
                    if letter!=letter2:
                        if letter2=='.': # broken snake
                            ok=False
                        else:
                            adj[letter].append(letter2)
            else: # vertical
                for row in range(start[0],end[0]+1):
                        letter2=grid[row][start[1]]
                        if letter!=letter2:
                            if letter2=='.': # broken snake
                                ok=False
                            else:
                                adj[letter].append(letter2)
        if ok==False:
            allans.append(['NO'])
            continue
        
        # # check adj for cycles
        chars=startEnd.keys()
        # v=set()
        # for c in chars:
        #     if c in v: continue
        #     v.add(c)
        #     path={c}
        #     stack=[c]
        #     while stack:
        #         c=stack.pop()
        #         for nex in adj[c]:
        #             if nex in path: # has cycle
        #                 ok=False
        #                 break
        #             else:
        #                 path.add(c)
        #             if c not in v:
        #                 v.add(c)
        #                 stack.append(c)
        # if ok==False: # cycle detected
        #     allans.append(['NO'])
        #     continue
        
        # # run topological sort
        # order=[]
        # v=set()
        # def dfs(c):
        #     for nex in adj[c]:
        #         if nex not in v:
        #             v.add(nex)
        #             dfs(nex)
        #     order.append(c)
        # for c in chars:
        #     if c not in v:
        #         v.add(c)
        #         dfs(c)
        # order.reverse()
        
        # I just realised that he has to write in order a,b,c...
        # check that adj does not contradict order
        for u in chars:
            for v in adj[u]:
                if v<u:
                    ok=False
        if ok==False: # cycle detected
            allans.append(['NO'])
            continue
        
        order=sorted(chars)
        
        allans.append(['YES'])
        
        if len(order)==0:
            allans.append([0])
        else:
            allC='abcdefghijklmnopqrstuvwxyz'
            maxChar=order[-1]
            maxCharIdx=allC.index(maxChar)
            allans.append([maxCharIdx+1])
            dr,dc=startEnd[order[-1]][0] # dummy row and column to put other snakes
            dr+=1; dc+=1
            for i in range(maxCharIdx+1):
                if allC[i] not in order: # the other chars < maxChar that are not in grid
                    allans.append([dr,dc,dr,dc])
                else:
                    [r1,c1],[r2,c2]=startEnd[allC[i]]
                    r1+=1; c1+=1; r2+=1; c2+=1
                    allans.append([r1,c1,r2,c2])
        
    multiLineArrayOfArraysPrint(allans)
    
    return



import sys
# input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.

def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultValFactory,dimensionArr): # eg. makeArr(lambda:0,[n,m])
    dv=defaultValFactory;da=dimensionArr
    if len(da)==1:return [dv() for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(l,r):
    print('? {} {}'.format(l,r))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(x):
    print('! {}'.format(x))
    sys.stdout.flush()
 
inf=float('inf')
# MOD=10**9+7
MOD=998244353

from math import gcd,floor,ceil
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()
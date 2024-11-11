from heapq import heappush,heappop,heapify
from collections import deque,defaultdict,Counter
import itertools
from functools import *
from itertools import permutations,combinations,groupby
import sys
import bisect
import string
import math
import time
import random
def Golf():*a,=map(int,open(0))
def S_():return input()
def IS():return input().split()
def LS():return [i for i in input().split()]
def I():return int(input())
def MI():return map(int,input().split())
def LI():return [int(i) for i in input().split()]
def LI_():return [int(i)-1 for i in input().split()]
def NI(n):return [int(input()) for i in range(n)]
def NI_(n):return [int(input())-1 for i in range(n)]
def StoI():return [ord(i)-97 for i in input()]
def ItoS(nn):return chr(nn+97)
def LtoS(ls):return ''.join([chr(i+97) for i in ls])
def GI(V,E,Directed=False,index=0):
    org_inp=[]
    g=[[] for i in range(n)]
    for i in range(E):
        inp=LI()
        org_inp.append(inp)
        if index==0:
            inp[0]-=1
            inp[1]-=1
        if len(inp)==2:
            a,b=inp
            g[a].append(b)
            if not Directed:
                g[b].append(a)
        elif len(inp)==3:
            a,b,c=inp
            aa=(inp[0],inp[2])
            bb=(inp[1],inp[2])
            g[a].append(bb)
            if not Directed:
                g[b].append(aa)
    return g,org_inp
def GGI(h,w,search=None,replacement_of_found='.',mp_def={'#':1,'.':0}):
#h,w,g,sg=GGI(h,w,search=['S','G'],replacement_of_found='.',mp_def={'#':1,'.':0}) # sample usage
    mp=[1]*(w+2)
    found={}
    for i in range(h):
        s=input()
        for char in search:
            if char in s:
                found[char]=((i+1)*(w+2)+s.index(char)+1)
                mp_def[char]=mp_def[replacement_of_found]
        mp+=[1]+[mp_def[j] for j in s]+[1]
    mp+=[1]*(w+2)
    return h+2,w+2,mp,found
def TI(n):return GI(n,n-1)
def bit_combination(k,n=2):
    rt=[]
    for tb in range(n**k):
        s=[tb//(n**bt)%n for bt in range(k)]
        rt+=[s]
    return rt
def show(*inp,end='\n'):
    if show_flg:
        print(*inp,end=end)
YN=['YES','NO']
Yn=['Yes','No']
 
mo=10**9+7
inf=float('inf')
l_alp=string.ascii_lowercase
#sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().rstrip()

def ran_input():
    import random
    n=random.randint(4,16)
    rmin,rmax=1,10
    a=[random.randint(rmin,rmax) for _ in range(n)]
    return n,a

show_flg=False
show_flg=True

n=I()
h=n+2
mp= [[-2]*h]+ [[-2]+[None]*n+[-2] for i in range(n)] + [[-2]*h] 
ch=[[None]*h for i in range(h)]
gl=[]
fv=[]
for i in range(n):
    a=LI()
    for j in range(n):
        r,c=a[2*j:2*j+2]
        if (r,c)==(-1,-1):
            mp[i+1][j+1]=-1
            fv.append((i+1)*h+(j+1))
        else:
            mp[i+1][j+1]=r*h+c
            if (i+1)*h+(j+1)==mp[i+1][j+1]:
                ch[i+1][j+1]='X'
                gl.append(mp[i+1][j+1])
#show(fv,gl)
dc={-1:'R',1:'L',-h:'D',h:'U'}
while gl:
    Q=[gl.pop()]
    while Q:
        q=Q.pop()
        r,c=q//h,q%h
        for i in [+1,-1,+h,-h]:
            nr,nc=(q+i)//h,(q+i)%h
            if mp[nr][nc]==mp[r][c] and ch[nr][nc]==None:
                ch[nr][nc]=dc[i]
                Q.append(q+i)
while fv:
    Q=[fv.pop()]
    while Q:
        q=Q.pop()
        r,c=q//h,q%h
        for i in [+1,-1,+h,-h]:
            nr,nc=(q+i)//h,(q+i)%h
            if mp[nr][nc]==mp[r][c] and ch[nr][nc]==None:
                ch[nr][nc]=dc[i]
                if ch[r][c]==None:
                    ch[r][c]=dc[-i]
                Q.append(q+i)

#show(h,n)
for i in mp:
    0#show(*i)
for i in range(1,n+1):
    for j in range(1,n+1):
        if ch[i][j]==None:
            print('INVALID')
            exit()
print('VALID')
for i in range(1,n+1):
    show(''.join(ch[i][1:n+1]))




from collections import *
from itertools import *
from bisect import *
from heapq import *
import copy
#N=int(input())
#S=[list(map(int,input().split())) for i in range(N)]
idle=10**13
xs,ys,xt,yt=map(int,input().split())
N=int(input())
XYR=[list(map(int,input().split())) for i in range(N)]
XYR.append([xt,yt,0])#終点
XYR.append([xs,ys,0])#開始
"""for i in range(len(XYR)):
    XYR[i][0]*=idle
    XYR[i][1]*=idle
    XYR[i][2]*=idle"""
kyori=[[0 for i in range(len(XYR))] for n in range(len(XYR))]
for i in range(len(XYR)):
    for m in range(i,len(XYR)):
        if i==m:
            t=0
        else:
            x1,y1,r1=XYR[i]
            x2,y2,r2=XYR[m]
            t=max(((x2-x1)**2+(y2-y1)**2)**.5-r1-r2,0)

        kyori[i][m]=t
        kyori[m][i]=t
stack=sorted(kyori[-1])
heapify(stack)
Pdic={}
dic={}
kyoriset=set()
for i in range(len(XYR)):
    a=kyori[-1][i]
    Pdic.update({i:a})
    if not a in kyoriset:
        kyoriset.add(a)
        dic.update({a:[i]})
    else:
        dic[a].append(i)
visited=set([len(XYR)-1])
while stack:
    m=heappop(stack)
    a=dic[m].pop()
    if a==len(XYR)-2:
        print(m/idle)
        exit()
    if not a in visited:
        visited.add(a)
        for i in range(len(XYR)):
            nm=kyori[a][i]+m
            if Pdic[i]>nm:
                Pdic[i]=nm
                heappush(stack,nm)
                if not nm in kyoriset:
                    kyoriset.add(nm)
                    dic.update({nm:[i]})
                else:
                    dic[nm].append(i)

#from math import *
#from collections import *
#from bisect import *
import sys
input=sys.stdin.readline
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())     # HEY DEAR!!!
t=inp()
while(t):
    t-=1
    n,m=ma()
    deg=[[] for i in range(n)]
    dma={i:[]  for i in range(n)}
    dmb={i:[]  for i in range(n)}
    for i in range(n):
        s=st()
        for j in range(n):
            deg[i].append(s[j])
            if(s[j]=='a'):
                dma[i].append(j)
            elif(s[j]=='b'):
                dmb[i].append(j)
    if(m==1):
        print("YES")
        print(1,2)
        continue
    fl=0
    for i in range(n):
        for j in range(n):
            if(i==j):
                continue
            if(deg[i][j]==deg[j][i]):
                fl=1
                pos=i+1
                pos2=j+1
                break
    if(fl):
        print("YES")
        for i in range(m+1):
            if(i%2):
                print(pos,end=' ')
            else:
                print(pos2,end=' ')
        print()
        continue
    if(m%2):
        print("YES")
        for i in range(m+1):
            print(i%2 +1,end=' ')
        print()
        continue
    if(n==2 ):
        print("NO")
        continue
    else:
        if((m//2)%2):
            ff=0
            for i in range(n):
                for j in range(n):
                    if(i==j):
                        continue
                    ha=deg[i][j]
                    if(ha=='a'):
                        if(len(dma[j])):
                            pos1=i+1
                            pos2=j+1
                            ll=0
                            for kk in dma[j]:
                                if(kk!=pos1-1):
                                    pos3=kk+1
                                    ll=1
                                    break
                            if(ll ^ 1):
                                continue
                            ff=1
                            break
                    else:
                        if(len(dmb[j])):
                            pos1=i+1
                            pos2=j+1
                            ll=0
                            for kk in dmb[j]:
                                if(kk!=pos1-1):
                                    pos3=kk+1
                                    ll=1
                                    break
                            if(ll ^ 1):
                                continue
                            ff=1
                            break
                if(ff):
                    break
            if(ff==0):
                print("NO")
                continue
            print("YES")
            for i in range(m//2 +1):
                if(i%2==0):
                    print(pos1,end=' ')
                else:
                    print(pos2,end=' ')
            for i in range(m//2):
                if(i%2):
                    print(pos2,end=' ')
                else:
                    print(pos3,end=' ')
        else:
            ff=0
            for i in range(n):
                for j in range(n):
                    if(i==j):
                        continue
                    ha=deg[i][j]
                    if(ha=='a'):
                        if(len(dmb[i])):
                            pos1=i+1
                            pos2=j+1
                            ll=0
                            for kk in dmb[i]:
                                if(kk!=pos2-1):
                                    pos3=kk+1
                                    ll=1
                                    break
                            if(ll ^ 1):
                                continue
                            ff=1
                            break
                    else:
                        if(len(dma[i])):
                            pos1=i+1
                            pos2=j+1
                            ll=0
                            for kk in dma[i]:
                                if(kk!=pos2-1):
                                    pos3=kk+1
                                    ll=1
                                    break
                            if(ll ^ 1):
                                continue
                            ff=1
                            break
                if(ff):
                    break
            if(ff==0):
                print("NO")
                continue
            print("YES")
            for i in range(m//2 +1):
                if(i%2==0):
                    print(pos1,end=' ')
                else:
                    print(pos2,end=' ')
            for i in range(m//2):
                if(i%2):
                    print(pos1,end=' ')
                else:
                    print(pos3,end=' ')
        print()
                    
                    
        
        
        
            
    
        

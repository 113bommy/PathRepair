#from math import *
#from bisect import *
from collections import *
#from random import *
#from decimal import *"""
#from heapq import *
#from random import *
import sys
input=sys.stdin.readline
#sys.setrecursionlimit(3*(10**5))
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=inp()
gl={'a':'b','b':'a'}
gl1={'c':'d','d':'c'}
while(t):
    t-=1
    n,m,k=ma()
    if(n%2==m%2 and n%2==0):
        if(k%2):
            print("NO")
        else:
            print("YES")
            shift=0
            if(n%4==0):
                shift=1
            cur='a'
            res=[['$' for i in range(m)] for j in range(n)]
            for i in range(m):
                for j in range(0,n,2):
                    res[j][i]=cur
                    res[j+1][i]=cur
                    cur=gl[cur]
                if(shift):
                    cur=gl[cur]
            shift=0
            if(m%4==0):
                shift=1
            cur='c'
            for i in range(0,m,2):
                if(k==0):
                    break
                for j in range(0,n):
                    k-=1
                    res[j][i]=cur
                    res[j][i+1]=cur
                    cur=gl1[cur]
                    if(k==0):
                        break
                if(k==0):
                    break
                if(1):
                    cur=gl1[cur]
            for i in res:
                print(''.join(i))
            
    else:
        if(0):
            if(m%2):
                print("NO")
            else:
                print("YES")
            continue
        else:
            tot=k*2
            if(n%2):
                re=k-m//2
                if(re>=0 and re%2==0):
                    print("YES")
                    shift=0
                    if((n-1)%4==0):
                        shift=1
                    cur='a'
                    res=[['$' for i in range(m)] for j in range(n)]
                    for i in range(m):
                        for j in range(1,n,2):
                            res[j][i]=cur
                            res[j+1][i]=cur
                            cur=gl[cur]
                        if(shift):
                            cur=gl[cur]
                    cur='c'
                    for i in range(0,m,2):
                        res[0][i]=cur
                        res[0][i+1]=cur
                        cur=gl1[cur]
                    k-=m//2
                    if(m%4==0):
                        cur=gl1[cur]
                    for i in range(1,n,2):
                        if(k==0):
                            break
                        for j in range(0,m,2):
                            k-=2
                            res[i][j]=cur
                            res[i][j+1]=cur
                            cur=gl1[cur]
                            res[i+1][j]=cur
                            res[i+1][j+1]=cur
                            if(k==0):
                                break
                        if(k==0):
                            break
                        if(1):
                            cur=gl1[cur]
                    for i in res:
                        print(''.join(i))
                else:
                    print("NO")
            else:
                if(k%2==0 and 2*k<=n*(m-1)):
                    print("YES")
                    shift=0
                    if(n%4==0):
                        shift=1
                    cur='a'
                    res=[['$' for i in range(m)] for j in range(n)]
                    for i in range(m):
                        for j in range(0,n,2):
                            res[j][i]=cur
                            res[j+1][i]=cur
                            cur=gl[cur]
                        if(shift):
                            cur=gl[cur]
                    shift=0
                    if(m%4==0):
                        shift=1
                    cur='c'
                    for i in range(0,m,2):
                        if(k==0):
                            break
                        for j in range(0,n):
                            k-=1
                            res[j][i]=cur
                            res[j][i+1]=cur
                            cur=gl1[cur]
                            if(k==0):
                                break
                        if(k==0):
                            break
                        if(1):
                            cur=gl1[cur]
                    for i in res:
                        print(''.join(i))
                else:
                    print("NO")

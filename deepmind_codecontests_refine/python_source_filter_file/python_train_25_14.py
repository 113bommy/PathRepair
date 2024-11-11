import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math 
from collections import defaultdict


for _ in range(ri()):
    n=ri()
    l=[]
    for __ in range(n):l.append(list(input()))
    ans=[]
    x=[l[0][1],l[1][0]]
    y=[l[n-2][n-1],l[n-1][n-2]]
    z=x.count('0')+y.count('0')
    if (x.count('1')==0 and y.count('0')==0) or (x.count('0')==0 and y.count('1')==0):
        wi(0)
    elif z==4 or z==0:
        wi(2)
        print(1,2)
        print(2,1)
    elif z==1:
        if '0' in x:
            if x[0]=='0':
                wi(1)
                print(2,1)
            else:
                wi(1)
                print(1,2)
        else:
            if y[0]=='0':
                wi(1)
                print(n,n-1)
            else:
                wi(1)
                print(n-1,n)
    elif z==2:
        wi(2)
        if x[0]=='1':
            print(2,1)
        else:
            print(1,2)
        if y[0]=='0':
            print(n-1,n)
        else:
            print(n,n-1)
    else:
        if '1' in x:
            if x[0]=='0':
                wi(1)
                print(2,1)
            else:
                wi(1)
                print(1,2)
        else:
            if y[0]=='1':
                wi(1)
                print(n,n-1)
            else:
                wi(1)
                print(n-1,n)
        

    '''if l[0][1]=='0':
       ans.append([1,2])
    if l[1][0]=='0':
        ans.append([2,1])
    if l[n-2][n-1]=='1':
        ans.append([n-1,n])
    if l[n-1][n-2]=='1':
        ans.append([n,n-1])
    wi(len(ans))
    for i in ans:
        wia(i)'''

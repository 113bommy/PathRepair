from sys import stdout,stdin
from collections import defaultdict,deque
import math
d=defaultdict(tuple)
d[('1','1','1','1')]=('0','0','1','0')
d[('1','1','1','0')]=('0','0','0','0')
d[('1','1','0','1')]=('0','0','0','0')
d[('1','1','0','0')]=('0','0','1','0')
d[('1','0','1','1')]=('0','0','0','0')
d[('1','0','1','0')]=('0','0','0','1')
d[('1','0','0','1')]=('1','1','1','0')
d[('1','0','0','0')]=('0','1','1','0')
d[('0','1','1','1')]=('0','0','0','0')
d[('0','1','1','0')]=('1','0','1','1')
d[('0','1','0','1')]=('1','0','0','0')
d[('0','1','0','0')]=('1','0','0','1')
d[('0','0','1','1')]=('0','1','0','0')
d[('0','0','1','0')]=('1','0','0','1')
d[('0','0','0','1')]=('0','1','1','0')
d[('0','0','0','0')]=('0','0','0','0')


t=int(stdin.readline())
for _ in range(t):
    #n=int(stdin.readline())
    n,m=map(int,stdin.readline().split())
    #l=list(map(int,stdin.readline().split()))
    l=[]
    for i in range(n):
        l.append(list(stdin.readline().strip()))
    x,y=False,False
    if n%2!=0:
        n-=1
        x=True
    if m%2!=0:
        m-=1
        y=True
    
    an=0
    ans=[]
    for i in range(0,n,2):
        for j in range(0,m,2):
            temp=(l[i][j],l[i][j+1],l[i+1][j],l[i+1][j+1])
            while(temp!=('0','0','0','0')):
                an+=1
                ll=[]
                kk=d[temp]
                if kk[0]!=temp[0]:
                    ll.append(i+1)
                    ll.append(j+1)
                if kk[1]!=temp[1]:
                    ll.append(i+1)
                    ll.append(j+2)
                if kk[2]!=temp[2]:
                    ll.append(i+2)
                    ll.append(j+1)
                if kk[3]!=temp[3]:
                    ll.append(i+2)
                    ll.append(j+2)
                temp=kk
                ans.append(ll)
    #print(ans)
    if x:
        for j in range(0,m,2):
            temp=('0','0',l[n][j],l[n][j+1])
            while(temp!=('0','0','0','0')):
                an+=1
                ll=[]
                kk=d[temp]
                if kk[0]!=temp[0]:
                    ll.append(n)
                    ll.append(j+1)
                if kk[1]!=temp[1]:
                    ll.append(n)
                    ll.append(j+2)
                if kk[2]!=temp[2]:
                    ll.append(n+1)
                    ll.append(j+1)
                if kk[3]!=temp[3]:
                    ll.append(n+1)
                    ll.append(j+2)
                temp=kk
                ans.append(ll)
    if y:
        for i in range(0,n,2):
            temp=('0',l[i][m],'0',l[i+1][m])
            while(temp!=('0','0','0','0')):
                an+=1
                ll=[]
                kk=d[temp]
                if kk[0]!=temp[0]:
                    ll.append(i+1)
                    ll.append(m)
                if kk[1]!=temp[1]:
                    ll.append(i+1)
                    ll.append(m+1)
                if kk[2]!=temp[2]:
                    ll.append(i+2)
                    ll.append(m)
                if kk[3]!=temp[3]:
                    ll.append(i+2)
                    ll.append(m+1)
                temp=kk
                ans.append(ll)
    if(x&y):
        temp=('0','0','0',l[n][m])
        while(temp!=('0','0','0','0')):
            an+=1
            ll=[]
            kk=d[temp]
            if kk[0]!=temp[0]:
                ll.append(n)
                ll.append(m)
            if kk[1]!=temp[1]:
                ll.append(n)
                ll.append(m+1)
            if kk[2]!=temp[2]:
                ll.append(n+1)
                ll.append(m)
            if kk[3]!=temp[3]:
                ll.append(n+1)
                ll.append(m+1)
            temp=kk
            ans.append(ll)
    print(an)
    for i in range(an):
        print(*ans[i])

    
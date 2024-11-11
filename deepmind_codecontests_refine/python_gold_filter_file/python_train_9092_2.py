import sys
import math
import collections
import heapq
import decimal
input=sys.stdin.readline
n=int(input())
l=sorted([int(i) for i in input().split()],reverse=True)
d=collections.Counter(l)
s=sum(l)
if(s%3==0):
    for i in range(n):
        l[i]=str(l[i])
    if(l[0]=='0'):
        print(0)
    elif(l[n-1]!='0'):
        print(-1)
    else:
        print(''.join(l))
elif(s%3==1):
    k=-1
    for i in range(n-1,-1,-1):
        if(l[i]%3==1):
            k=i
            break
    if(k==-1):
        t=[-1,-1]
        c=0
        for i in range(n-1,-1,-1):
            if(l[i]%3==2):
                if(c==0):
                    t[1]=i
                    c+=1
                else:
                    t[0]=i
                    c+=1
            if(c==2):
                break
        if(t[0]==-1):
            print(-1)
        else:
            ans=[]
            for i in range(t[0]):
                ans.append(str(l[i]))
            for i in range(t[0]+1,t[1]):
                ans.append(str(l[i]))
            for i in range(t[1]+1,n):
                ans.append(str(l[i]))
            if(ans[0]=='0'):
                print(0)
            elif(ans[-1]!='0'):
                print(-1)
            else:
                print(''.join(ans))
    else:
        ans=[]
        for i in range(k):
            ans.append(str(l[i]))
        for i in range(k+1,n):
            ans.append(str(l[i]))
        if(ans[0]=='0'):
            print(0)
        elif(ans[-1]!='0'):
            print(-1)
        else:
            print(''.join(ans))
else:
    k=-1
    for i in range(n-1,-1,-1):
        if(l[i]%3==2):
            k=i
            break
    if(k==-1):
        t=[-1,-1]
        c=0
        for i in range(n-1,-1,-1):
            if(l[i]%3==1):
                if(c==0):
                    t[1]=i
                    c+=1
                else:
                    t[0]=i
                    c+=1
            if(c==2):
                break
        if(t[0]==-1):
            print(-1)
        else:
            ans=[]
            for i in range(t[0]):
                ans.append(str(l[i]))
            for i in range(t[0]+1,t[1]):
                ans.append(str(l[i]))
            for i in range(t[1]+1,n):
                ans.append(str(l[i]))
            if(ans[0]=='0'):
                print(0)
            elif(ans[-1]!='0'):
                print(-1)
            else:
                print(''.join(ans))
    else:
        ans=[]
        for i in range(k):
            ans.append(str(l[i]))
        for i in range(k+1,n):
            ans.append(str(l[i]))
        if(ans[0]=='0'):
            print(0)
        elif(ans[-1]!='0'):
            print(-1)
        else:
            print(''.join(ans))
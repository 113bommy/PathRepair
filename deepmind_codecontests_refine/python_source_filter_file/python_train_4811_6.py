import sys
import bisect as bi
import math
from collections import defaultdict as dd
input=sys.stdin.readline
##sys.setrecursionlimit(10**7)
def cin():
    return map(int,sin().split())
def ain():            
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())
for i in range(1):
    n,k=cin()
    s=sin().strip()
    fw=s[:k];f=0
    mul=n//k;mod=n%k
    for i in range(k,n-k+1,k):
        if(s[i:i+k]>fw):
            f=1
            break
        elif(s[i:i+k]<fw):
            f=2
            continue
    if(f==0):
        f=2
        if mod!=0:
            if(fw[:mod]<s[mul*k:n]):
                f=1
    if(f==1):
        l=fw[::-1]
        revs="";carry=0
        for i in range(len(l)):
            if(l[i]=='9'):
                revs+='0'
            else:
                revs+=str(int(l[i])+1)
                if(i<len(l)):revs+=l[i+1:]
                break
        revs=revs[::-1]
    elif(f==2):
        revs=fw
    ans=revs*mul+revs[0:mod]
    print(n)
    print(ans)

        
            
    
##    n=inin()
##    a=sin().strip()
##    b=sin().strip()
##    head=a[0];curr=a[-1],ans=[];c=0
##    for i in range(n-1,-1,-1):
##        if(b[i]==curr):
##            continue
##        else:
##            if(head==curr):l+=[1]
##            c+=1
##            head=curr^curr
##            if(c%2==1):curr=l[n-i]^l[n-i]
##            else:curr=l[i-1]^l[i-1]
##            l+=[i]
            
                
                
    
    
        
    
    

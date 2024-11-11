from sys import stdin,stdout
from itertools import combinations
from collections import defaultdict
import math
import heapq

def listIn():
    return list((map(int,stdin.readline().strip().split())))

def stringListIn():
    return([x for x in stdin.readline().split()])
    
def intIn():
    return (int(stdin.readline()))

def stringIn():
    return (stdin.readline().strip())


if __name__=="__main__":
    n=intIn()
    a=listIn()
    if len(set(a))==1:
        print(0)
        exit(0)
    else:
        di={}
        mp={}
        for i in range(1,n+1):
            ele=a[i-1]
            if ele not in di:
                di[ele]=1
                mp[ele]=[i]
            else:
                di[ele]+=1
                mp[ele].append(i)
        #print(di)
        #print(mp)
        mx=max(di.values())
        for ele in di:
            if di[ele]==mx:
                maxx=ele
                break
        op=n-mx
        pos=mp[maxx]
        ini=0
        last=n
        print(op)
        #print(maxx,pos)#no. of operations
        cnt=0
        for p in pos:
            for i in range(p-1,ini,-1):
                if a[i-1]>maxx:
                    print(2,i,i+1)
                    cnt+=1
                else:
                    print(1,i,i+1)
                    cnt+=1
            ini=p
            if cnt==op:
                break
        #print(ini)
        if pos[len(pos)-1]!=n:
            for i in range(ini,n,1):
                if a[i]>maxx:
                    print(2,i+1,i)
                    cnt+=1
                else:
                    print(1,i+1,i)
                    cnt+=1
                if cnt==op:
                    break
            
                
            
            
        
        
        
    
    
    

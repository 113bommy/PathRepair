from sys import stdin,stdout
from itertools import combinations
from collections import defaultdict
import math

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
    b=list(range(1,n+1))
    ans=0
    di={}
    for i in range(2*n):
        if a[i] not in di:
            di[a[i]]=[]
        di[a[i]].append(i)
    #print(di)
    for i in range(n):
        if b[i]==1:
            ans+=sum(di[a[i]])
        else:
            l1=di[b[i]]
            l2=di[b[i-1]]
            m1,m2=abs(l2[0]-l1[0]),abs(l2[0]-l1[1])
            m3,m4=abs(l2[1]-l1[0]),abs(l2[1]-l1[1])
            m5,m6=min(m1,m2),min(m3,m4)
            if m5==m1:
                m7=m5+m4
            else:
                m7=m5+m3
            
            if m6==m3:
                m8=m6+m2
            else:
                m8=m6+m1
            #print(m7,m8)
            ans+=min(m7,m8)
            
        #print(ans)
    print(ans)
        
        
        
        
    
    

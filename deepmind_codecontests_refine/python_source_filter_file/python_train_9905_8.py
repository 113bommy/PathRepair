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

def neutral(zo,oz,oo,l):
    l3=l
    if l3%2==0:
        oz=oz+oo[:l3//2]
        zo=zo+oo[l3//2:]
    else:
        oz=oz+oo[:l3//2]+[zo[0]]
        zo=zo[1:]+oo[l3//2:]
    return [zo,oz]
    

if __name__=="__main__":
    n=intIn()
    c=stringIn()
    a=stringIn()
    zz,oo,zo,oz=[],[],[],[]
    for i in range(n):
        if c[i]=="0" and a[i]=="0":
            zz.append(i+1)
        elif c[i]=="0" and a[i]=="1":
            zo.append(i+1)
        elif c[i]=="1" and a[i]=="0":
            oz.append(i+1)
        else:
            oo.append(i+1)
    #print(zz,oz,zo,oo) 
    
    l1,l2=len(zo),len(oz)
    l3,l4=len(oo),len(zz)
        
    if len(oz)==n or len(zo)==n:
        print(-1)
        exit(0)
    if len(oo)==n or len(zz)==n:
        print(list(range(1,n//2+1)))
        exit(0)
    if len(oz)==0 and len(zo)==0:
        if l3%2==0:
            zo=zo+oo[:l3//2]+zz[:l4//2]
            oz=oz+oo[l3//2:]+zz[l4//2:]
            #print(zo,oz)
            oz.sort()
            print(*oz)
        else:
            print(-1)
        exit(0)
        
    
    diff=abs(l1-l2)
    if diff==0:
        zo,oz=neutral(zo,oz,oo,l3)
    else:
        d=abs(diff-l3)
        m=min(diff,l3)
        #print(d,m)
        if l2>l1:
            if diff>=l3:
                zo=zo+oo[:m]+oz[:d]
                oz=oz[d:]+oo[m:]
            else:
                zo=zo+oo[:m]
                oo=oo[m:]
                zo,oz=neutral(zo,oz,oo,d)
        else:
            if diff>=l3:
                oz=oz+oo[:m]+zo[:d]
                zo=zo[d:]+oo[m:]
            else:
                oz=oz+oo[:m]
                oo=oo[m:]
                zo,oz=neutral(zo,oz,oo,d)
    
    
    ll1,ll2=len(zo),len(oz)
    cn=n//2
    lr1=cn-ll1
    zo=zo+zz[:lr1]
    oz=oz+zz[lr1:]
    lll1,lll2=len(zo),len(oz)
    if len(zo)!=len(oz):
        print(-1)
    else:
        cnt1,cnt2=0,0
        #print(zo,oz)
        for i in range(lll1):
            if a[zo[i]-1]=="1":
                cnt1+=1
        for i in range(lll2):
            if c[oz[i]-1]=="1":
                cnt2+=1
        if cnt1==cnt2:
            oz.sort()
            print(*oz)  
        else:
            print(-1)
     
        
        
            
        
    
    

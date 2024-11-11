from sys import stdin,stdout
from itertools import combinations
from collections import defaultdict,Counter
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
    n,m,k=listIn()
    li=listIn()
    li2=li.copy()
    idx=0
    count=0
    d=0
    d1=0
    while(d!=m):
        i=idx
        d1+=1
        while(i<m):
            li2[i]=(li[i]-d-1)//k
            if i!=idx:
                if li2[i]!=li2[i-1]:
                    count+=1
                    idx=i
                    break
                else:
                    d1+=1
            i+=1
        d=d1
        #print(li2)
    print(count+1)
from sys import stdin,stdout
from itertools import combinations
from collections import defaultdict,OrderedDict
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
    a=list(map(lambda x:x+n+1,a))
    
    print(n+1)
    print(1,n,n+1)
    mod_arr=[0]*n
    b=a.copy()
    for i in range(n):
        mod_arr[i]=a[i]-i
        print(2,i+1,mod_arr[i])
        for j in range(i+1):
            b[j]=b[j]%mod_arr[i]
    #print(mod_arr)
    #print(b)
    
    
    
    
    
from sys import stdin,stdout
from itertools import combinations
from collections import defaultdict

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
    b=listIn()
    if n==k:
        print(n)
    else:
        diff=[]
        for i in range(1,n):
            diff.append(b[i]-b[i-1])
        a=sorted(diff)
        c=0
        ans=sum(a[:-(k-1)])
        print(ans+k)
                
                
            
        
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
    if n==3:
        print(a)
    else:
        diff=[]
        b=sorted(a)
        di={}
        for ele in a:
            if ele not in di:
                di[ele]=1
            else:
                di[ele]+=1
        if n%2!=0:
            ans=[b[0]]
            i=1
            while i<n:
                ans=[b[i]]+ans
                ans+=[b[i+1]]
                i+=2
                #print(ans)
            print(*ans)
        else:
            ans=[]
            i=0
            while i<n:
                ans=[b[i]]+ans
                ans+=[b[i+1]]
                i+=2
                #print(ans)
            print(*ans)
            
            
            
            


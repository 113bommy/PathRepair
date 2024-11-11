import sys
import bisect as b
import math
from collections import defaultdict as dd
input=sys.stdin.readline
#sys.setrecursionlimit(10**7)
mo=10**9+7
def cin():
    return map(int,sin().split())
def ain():            
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())
def pref(a,n,f):             
    pre=[0]*n
    if(f==0):         ##from beginning
        pre[0]=a[0]
        for i in range(1,n):
            pre[i]=a[i]+pre[i-1]
    else:              ##from end
        pre[-1]=a[-1]
        for i in range(n-2,-1,-1):
            pre[i]=pre[i+1]+a[i]
    return pre
maxint=10**24 
def kadane(a,size): 
       
    max_so_far = -maxint - 1
    max_ending_here = 0
       
    for i in range(0, size): 
        max_ending_here = max_ending_here + a[i] 
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 
  
        if max_ending_here < 0: 
            max_ending_here = 0   
    return max_so_far 
for _ in range(inin()):
    n=inin()
    a=ain()
    ans=sum(a[0:n:2])
    l3=[]
    l4=[]
    for i in range(0,n-1,2):
        l3+=[a[i+1]-a[i]]
    for i in range(2,n-1,2):
        l4+=[a[i-1]-a[i]]
    print(max(kadane(l3,len(l3)),kadane(l4,len(l4)))+ans)
            
    
    

        
        
    
                
                
                
                

        
            
            
                
            
                
    
 
        
    
    
    
    




    


   
        
    
    
    
    




    



import sys
import math
input=sys.stdin.readline

n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
l=[[0 for i in range(2)] for j in range((2*(10**5))+1)]
for i in range(n):
    l[arr[i]][1]+=1
    cnt=0
    while(arr[i]>0):
        
        arr[i]=arr[i]//2
        cnt+=1
        if(l[arr[i]][1]<k):
            l[arr[i]][0]+=cnt
            l[arr[i]][1]+=1
ans=100000000000
for i in range(len(l)):
    if(l[i][1]==k):
        ans=min(ans,l[i][0])
print(ans)
            
    
    
            

    
    
        
    
    

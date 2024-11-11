from sys import exit
from heapq import heapify,heappush,heappop

n=int(input())
low=[]
high=[]
pos=0
mid=set()
for i in range(n):
    #print(high,low,mid)
    s=input().split()
    #print(s)
    x=int(s[1])
    s=s[0]
    #print(s[0],s[0]=='ADD')
    if(s=='ADD'):
        if(len(low) and x<-1*low[0]):
            heappush(low,(-x))
        elif(len(high) and x>high[0]):
            heappush(high,x)
        else:
            mid.add(x)
    else:      
        if(len(low) and x==-low[0]):
            heappop(low)
        elif(len(high) and x==high[0]):
            heappop(high)
        elif(x in mid):        
            pos+=1    
        else:
            print(0)
            exit()
        for j in mid:
            if(j>x):
                heappush(high,j)
            elif(j<x):
                heappush(low,-j)
        mid=set()
mod=int(1e9+7)
print(pow(2,pos,mod)*(len(mid)+1))
            
            


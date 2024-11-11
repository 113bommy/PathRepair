from heapq import *
a=int(input())
import sys
input=sys.stdin.readline
for i in range(a):
    x=int(input())
    ram=[]
    heappush(ram,(-1*x,0,x-1))
    ans=[0 for i in range(x)]
    count=0
    while(count<x):
        temp=heappop(ram)
        
        ans[(abs(temp[1])+temp[2])//2]=count+1
    
        siz=abs(temp[0])
        kem=abs(temp[1])
        count+=1
        if(siz%2==1):
            heappush(ram,(-1*(siz//2),temp[1],kem+(siz//2)-1))
            heappush(ram,(-1*(siz//2),kem+(siz//2)+1,temp[2]))
        else:
            heappush(ram,(-1*(siz//2),((abs(temp[1])+temp[2])//2)+1,temp[2]))
            if(siz//2>1):
                
                heappush(ram,(-1*((siz//2)-1),temp[1],((kem+temp[2])//2)-1))
        
    print(ans[-1])

    

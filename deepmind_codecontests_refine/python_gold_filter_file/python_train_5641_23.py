import sys

n=int(input())

while n > 0:
    n-=1
    
    b,p,f = map(int,sys.stdin.readline().split())
    h,c= map(int,sys.stdin.readline().split())
    '''b=int(l1[0])
    p=int(l1[1])
    f=int(l1[2])
    h=int(l2[0])
    c=int(l2[1])'''
    
    if b < 2:
        print(0)
        continue
    if c > h:
        profit=0
        
        t=f
        while (t*2 > b):
            t-=1
        b-=(t*2)
        profit +=(t*c)
        
        
        
        t=p
        while (t*2 > b):
            t-=1
        b-=(t*2)
        profit +=(t*h)
       
        
        print(profit)
        continue
    else:
        profit=0
        t=p
        while (t*2 > b):
            t-=1
        b-=(t*2)
        profit +=(t*h)
        
        t=f
        while (t*2 > b):
            t-=1
        b-=(t*2)
        profit +=(t*c)
        
        
        print(profit)
        
        
    
    
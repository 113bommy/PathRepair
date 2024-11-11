t  = int(input())

i = 0
while i<t:
 a,b = map(int,input().split())   
 if a>b:
    print(a)
    
 else:
    l = b//a
    b = b+l
    while(((b)-(a*l))>=a):
        
       c  = ((b)-(a*l))//a
       b = b+c
       l = l+c
     
    print(b)   
 i= i+1  

n=int(input())
a=1;
b=2;
c=0;
li=[];
if n>0:
    for i in range(1,n+1):
        li.append(a);
        c=a+b;
        a=b;
        b=c;
        
for i in range(1,n+1):
    if i in li:
        print('O',end='')
    else:
        print('o',end='')
    
            
        
    
    

    
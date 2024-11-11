n = int(input());
r="";s=0;y=0;
one=2;one2=0;
if n > 2:
    for i in range(1,n):
        a=(((i+1)*i)//2)-1
        #print("a=",a,"s=",s,"y=",y)
        if(a<=n):
            y=i
            s=a
    if(s==n):pass;
    elif(s+1==n):
        one=1
        one2=1
    else:
        y-=1
        a=(((y+1)*y)//2)
        r = n-a
        one2=1
        if(a+r==n):
            one=1
            one2=2
        
    
            
else:
    one2=2
    r = n
    
print(y-1+one2)

for i in range(one,y+1):print(i,end=' ');

print(r)


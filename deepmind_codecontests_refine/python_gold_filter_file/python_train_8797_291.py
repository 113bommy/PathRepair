n=int(input())
s=0
while (n != 0) :
    if ( n>= 5 ) :
        s+=1
        n=n-5
        
    elif ( n>= 4 ) :
        s+=1
        n=n-4
        
    elif ( n>= 3 ) :
        s+=1
        n=n-3
        
    elif ( n>= 2 ) :
        s+=1
        n=n-2
        
    elif ( n>= 1 ) :
        s+=1
        n=n-1
        
print(s) 

n = int( input())
if( n ==1):
    print(1)
    print(1,1)
else:
    if( n%2==0):
        m=2
        m+= ( n/2 -1 )
    else:
        m=int( n/2)
    print(int(m) )
    x=1
    y=1
    for i in range(1,n+1):
        print(x,y)
        if( i%2==0):
            y+=1
        else:
            x+=1
            
        
        
    
    
'''
x,y,z= map( int , input().split())
if(z==0):
    if( x-y == 0):
        print('0')
    elif(x>y):
        print('+')
    else:
        print('-')

elif( abs(x-y)<= z):
    print( "?")
else:
    if( x >y):
        print('+')
    else:
        print('-')
'''

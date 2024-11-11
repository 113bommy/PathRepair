n = int ( input ( ))
z=[]
for i in range ( n ) :
    a = list(map(int,input().split()))
    e=a[0]//a[3]
    e-=a[1]//a[3] - ((a[2]-1)//a[3])
    z +=[e]
for i in z:
    print ( i )
            

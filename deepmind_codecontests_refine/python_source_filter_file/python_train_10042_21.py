x = int(input())
b = 0
a=0
while b < 50 :
    n = (b*(b+1)//2) 
    if ( n == x):
        a = n
        print ("yes")
        break
    b = b+1
    
if ( a == 0 ):
    print ("no")    


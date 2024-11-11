a=int(input())

for ifei in range(a):
    vals=input().split()

    n=int(vals[0])
    k=int(vals[1])

    floor=n-1
    num=k//floor
    extra=k%floor

    val=num*n
    if extra!=0:
        
        print (val+1)
    else:
        print (val-1)
                    

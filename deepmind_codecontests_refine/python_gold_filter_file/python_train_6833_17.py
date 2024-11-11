n,k=(int(x) for x in input().split())
if k==1:
    print(n)
else: 
    p=0
    while n != 0 :
        p+=1
        n//=2
    print(2**p-1)
    

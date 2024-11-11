number=int(input())
for i in range(number):
    a=int(input())
    k=30
    while k>=1:
        if a/(2**k-1)!=a//(2**k-1):
            k-=1
        else:
            print(int(a/(2**k-1)))
            break
    

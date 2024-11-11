
n = int(input())
a = [int(i) for i in input().split()] 
if n == 1 : 
    print(1,1)
    print(-a[-1])
    print(1,1)
    print(0); print(1,1);print(0)
else :  
    print(1,n)  
    for i in range(n) :
        k = (n-1-a[i])*n
        a[i]+= k
        print(k , sep=" ",end = " ")
    print()    
    print(1,n-1)
    for i in range(n-1) :
        print(-(a[i]),sep=" " , end= " ")
    print()    
    print(n,n)
    print(0)        
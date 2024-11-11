for x in range(int(input())):
    n = int(input())
    m=list(map(int,input().split()))
    k=0
    a=0
    for i in range(n-1):
        k=max(k,m[i])
        if m[i+1]-k<0:

            a=max(k-m[i+1],a)
    if a>0:
        print(len(bin(a))-2)
    else:
        print(0)
                
                
        
    
    
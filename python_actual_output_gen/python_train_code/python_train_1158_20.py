for x in range(int(input())):
    
    n,k=list(map(int,input().split()))
    if(k%n==0):
        #print(k)
        print(n*(k//(n-1))-1)
    else:
        #print(k,1)
        print(n*(k//(n-1))+k%(n-1))
    
        
for _ in range(int(input())):
    x,y,k = map(int,input().split())
    #print((y*k+k-1+x-2))
    
    print((y*k+k-1+x-2)//(x-1))
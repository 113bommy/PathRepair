for t in range(int(input())):
    x,y,k=map(int,input().split())
    print((k*y+k-1+x-2)//(x-1)+k)
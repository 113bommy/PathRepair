for t in range(int(input())):
    x,y,k=map(int,input().split())
    print((k+k*y+x-0.5)//(x-1)+k)
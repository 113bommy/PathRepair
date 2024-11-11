for _ in range(int(input())):
    x,y,k=map(int,input().split())
    print((k-1+y*k+x-2)//(x-1)+k)
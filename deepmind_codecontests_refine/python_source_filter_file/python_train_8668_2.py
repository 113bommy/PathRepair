t=int(input())
for _ in range(t):
    x,y,k=map(int,input().split())
    
    print((k+k*y-1)//(x-1)+k)
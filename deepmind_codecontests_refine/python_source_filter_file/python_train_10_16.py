n=int(input())
for k in range(n):
    a,b,c=map(int,input().split())
    print((b//c)*c+c)

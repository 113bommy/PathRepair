n=int(input())
while n>0:
    k,x=map(int,input().split())
    print(x+(k-1)*9)
    n-=1
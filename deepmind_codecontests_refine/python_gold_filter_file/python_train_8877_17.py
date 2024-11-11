t=int(input())
while(t>0):
    t-=1
    a,b,c,d=map(int,input().split())
    print(max(a+b,c+d))
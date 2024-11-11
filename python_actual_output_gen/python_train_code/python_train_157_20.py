t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    x=min(a,b,(a+b)/3)
    print(x)
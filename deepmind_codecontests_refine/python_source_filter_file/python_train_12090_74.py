t=int(input())
sum=0
count=0
for i in range(1,t+1,1):
    x,y=map(int,input().split())
    sum=2*y
    if(x!=sum):
        print(x,sum-7)

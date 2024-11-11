
t=int(input())
for i in range(0,t):
    n,m=map(int,input().strip().split(" "))
    flag=0
    for i in range(0,n):
        a,b=map(int,input().strip().split(" "))
        c,d=map(int,input().strip().split(" "))
        if(a==d and c==b):
            flag=1
    if(flag==1 and m%2==0):
        print("yes")
    else:
        print("no")
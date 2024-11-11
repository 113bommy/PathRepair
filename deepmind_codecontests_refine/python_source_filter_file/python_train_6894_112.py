a=int(input())
for i in range(a):
    x,y=map(int,input().split())
    if(y%x==0):
        print("Yes")
    else:
        print("No")
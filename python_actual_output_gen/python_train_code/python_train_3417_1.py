t=int(input())
for i in range(t):
    n,x=map(int,input().split())
    if n<=2:
        print("1")
    else:
        n-=2
        flor=n/x
        if n%x!=0:
            flor+=1
        print(flor+1)
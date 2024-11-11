t=int(input())
while(t):
    t-=1
    n=int(input())
    a=[int(i) for i in input().split()]
    odd=0
    for i in a:
        if i%2==1:
            odd+=1
    if 2*odd==n:
        print("Yes")
    else:
        print("No")
t=int(input())
for _ in range(t):
    n=int(input())
    if(n==1):
        print(-1)
    elif((n-1)%3 == 0):
        for i in range(n-2):
            print(2,end="")
        print(43)
    else:
        for i in range(n-1):
            print(2,end="")
        print(3)

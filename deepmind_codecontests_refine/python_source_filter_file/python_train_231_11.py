t=int(input())
for t in range(t):
    n=int(input())
    for i in range(1,n):
        if(n==1):
            print(0)
            break
        elif(n/6==1):
            print(i)
            break
        elif(n%6==3):
            n=n*2
        elif(n%6==0):
            n=n//6
        else:
            print(-1)
            break

def pro(arr):
    
    n=len(arr)
    if(n==1):
        print(0)
        return 

    k=sum(arr)
    rem=k%n
    print(rem*(n-rem))

t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    pro(arr)
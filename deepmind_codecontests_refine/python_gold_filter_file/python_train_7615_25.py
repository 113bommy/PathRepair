t=int(input())
for i in range(t):
    n,k=map(int, input().strip().split())
    count=0
    while(n!=0):
        if(n%k==0):
            n=n//k
            count+=1
        else:
            count=count+(n%k)
            n=n-(n%k)
    print(count)        
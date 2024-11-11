t = int(input())
while(t):
    count = 0
    n,k = input().split()
    n=int(n)
    k=int(k)
    while(n):
        if n%k==0:
            n=n/k
            count = count+1
        else:
            count=count+(n%k)
            n=n-(n%k)
    print(int(count))
    t=t-1
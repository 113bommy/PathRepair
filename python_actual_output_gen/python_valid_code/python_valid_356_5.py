t = int(input())
for i in range(t):
    n,k = list(map(int,input().split(" ")))
    for i in range(k):
        temp = n
        mint=n%10
        maxt=n%10
        while(temp>0):
            mint = min(mint,temp%10)
            maxt = max(maxt,temp%10)
            temp//=10
        temp = n + mint*maxt
        if(temp==n):
            n=temp
            break
        else:
            n=temp
    print(n)
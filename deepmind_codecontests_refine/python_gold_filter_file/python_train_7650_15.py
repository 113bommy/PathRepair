n=int(input())
if n==1:
    print(0)
    print(*[])
else:
    prime=[1]*(n+1)
    prime[0]=prime[1]=0
    for i in range(2,int(n**0.5)+1):
        if prime[i]==1:
            p=2*i
            while p<=n:
                if prime[p]==1:
                    prime[p]=0
                p+=i
    l=[]
    for i in range(2,n+1):
        if prime[i]==1:
            count=1
            while i**count<=n:
                l.append(i**count)
                count+=1
    print(len(l))
    print(*l)
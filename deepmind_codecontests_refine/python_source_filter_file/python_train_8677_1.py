def pr(n,prime):
    p=2
    while p**2<=n:
            if prime[p]==True:
                for i in range(2*p,n+1,p):
                    prime[i]=False
            p+=1
n=int(input())
prime=[True]*(10**6+10)
pr(10**6+1,prime)
a=[int(x) for x in input().split()]
for i in a:
    b=int(i**0.5)
    if i**0.5-b!=0:
        print('NO')
        continue
    else:      
        if prime[b-1]==True:
            print('YES')
        else:
            print('NO')
    

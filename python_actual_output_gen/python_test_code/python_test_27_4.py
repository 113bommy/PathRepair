def sieve(n):
    primes=[1]*(n)
    for i in range(2,int(n**0.5)+1):
        if primes[i]==1:
            for j in range(2*i,n,i):
                primes[j]=0
    return primes
n=int(input())
# n=6
arr=sieve(n)
# print(arr)
cnt=0
ans=[]
for i in range(2,len(arr)):
    if arr[i]:
        x=i
        while n//x>0:
            # print(n,x,n//x)
            ans.append(x)
            x*=x
print(len(ans))
print(*ans)



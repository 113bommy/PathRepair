def nCr(n, r):
    return (fact(n) / (fact(r)
                       * fact(n - r)))


# Returns factorial of n
def fact(n):
    res = 1

    for i in range(2, n + 1):
        res = res * i

    return res
import collections
t=int(input())
for _ in range(t):
    n=int(input())
    ai=list(map(int,input().split()))
    for i in range(len(ai)):
        ai[i]=len(bin(ai[i]))
    d=collections.Counter(ai)
    ans=0
    for i in d.values():
        if i>1:
            ans+=i*(i-1)//2
    print(int(ans))


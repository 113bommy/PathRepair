from math import gcd


def countDivisibles(A, B, M):
    # Add 1 explicitly as A is divisible by M
    if (A % M == 0):

        return (B // M) - (A // M)+1

    # A is not divisible by M
    return ((B // M) - (A // M))


t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    xx, a = list(map(int, input().split()))
    y, b = list(map(int, input().split()))
    if a>b:
        xx,a,y,b=y,b,xx,a
    k = int(input())
    l = (a * b) // gcd(a, b)
    arr.sort(reverse=True)
    s = [0] * n
    s[0] = arr[0]
    for i in range(1,n):
        s[i]=s[i-1]+arr[i]

    ind=-1
    ans=0
    # print(s)
    for i in range(1, n + 1):
        x = countDivisibles(1, i, l)
        x1 = countDivisibles(1, i, b)
        x2 = countDivisibles(1, i, a)
        # print(x,x1,x2)
        # ans=(s[x-1]*(xx+y)+(s[x+(x1-x)-1]-s[x-1])*xx+(s[x+(x1-x)+(x2-x)-1]-s[x+(x1-x)-1])*y)
        if x==0 and x1!=0 and x2!=0:
            ans=max((s[x1 - 1] ) * y + (s[x1  + (x2 - x) - 1] - s[x1 - 1]) * xx,ans)
            ans=max((s[x2  - 1] ) * xx + (s[x2 + (x1 - x) - 1] - s[x2  - 1]) * y,ans)

        elif x==0 and x1==0 and x2!=0:

            ans = max(
                (s[x2- 1]) * xx , ans)
            # print(ans,i)
        elif x!=0 and x1!=0 and x2!=0:
            ans = max(
                s[x-1]*(xx+y)+(s[x + (x1 - x) - 1] - s[x - 1]) * y + (s[x + (x1 - x) + (x2 - x) - 1] - s[x + (x1 - x) - 1]) * xx, ans)
            ans = max(
                s[x-1]*(xx+y)+(s[x + (x2 - x) - 1] - s[x - 1]) * xx + (s[x + (x2 - x) + (x1 - x) - 1] - s[x + (x2 - x) - 1]) * y, ans)
            # print(i,ans,s[x + (x2 - x) - 1] - s[x - 1],s[x + (x2 - x) + (x1 - x) - 1] - s[x + (x2 - x) - 1])
        if ans>=k*100:
            ind=i
            break
    print(ind)

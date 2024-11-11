n = int(input())
k = int(input())
A = int(input())
B = int(input())
if k==1:
    print(A*(n-1))
else:
    ans = 0
    while(n!=1):
        if n>k:
            ans += (n%k)*A
            n -= n%k
        else:
            ans += (n-1)*A
            break
        while(n!=1 and n%k==0):
            ans += min(B, (n-n//k)*A)
            n = n//k
    print(ans)

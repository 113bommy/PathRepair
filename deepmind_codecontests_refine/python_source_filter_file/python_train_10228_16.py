def odd(n,k):
    if (n%2==0 and k%2==0) or (n%2!=0 and n%2!=0):
        if n>=k**2:
            return "YES"
    return "NO"
for t in range(int(input())): 
    n,k=list(map(int,input().split()))
    print(odd(n,k))
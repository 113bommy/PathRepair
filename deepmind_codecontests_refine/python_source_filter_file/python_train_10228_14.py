for _ in range(int(input())):
    n,k=map(int,input().split())
    p=n-k*k
    if(n%2==k%2 and p>0):
        print("YES")
    else:
        print("NO")
    
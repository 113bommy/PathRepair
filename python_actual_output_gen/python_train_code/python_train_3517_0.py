t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    if(n%2==k%2 and k<n//2-1):
        print("YES")
    else:
        print("NO")
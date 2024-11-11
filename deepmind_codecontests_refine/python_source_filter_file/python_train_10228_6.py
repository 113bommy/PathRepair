n=int(input())
while(n):
    a,b=map(int,(input().split()))
    if a%2==b%2 and b*b<=n:
            print("YES")
    else:
            print("NO")
    n=n-1
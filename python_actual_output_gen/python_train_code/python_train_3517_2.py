n=int(input())
t=n
while(t):
    a,b=map(int,(input().split()))
    if a%2==b%2 and b*b<=n:
            print("YES")
    else:
            print("NO")
    t=t-1
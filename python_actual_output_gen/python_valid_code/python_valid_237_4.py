
for _ in range(int(input())):
    n=int(input())
    s=list(map(int,input().split()))
    ans=1
    k=1
    s.sort()
    for i in range(n):
        if s[i]<=i+1:
            ans=i+1
    print(ans+1)
        
        

for _ in range(int(input())):
    n=int(input())
    s=sorted(map(int,input().split()))
    i=n-1
    while i>=0 and s[i]>=n-i:
        i-=1
    print(n-i+1)
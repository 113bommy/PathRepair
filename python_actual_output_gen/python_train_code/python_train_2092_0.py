for _ in range(int(input())):
    n = int(input())
    a = [*map(int,input().split())]
    ans = sum(max(a[i]-a[i+1],0) for i in range(n-1))
    print("YES" if ans<a[0] else "NO")

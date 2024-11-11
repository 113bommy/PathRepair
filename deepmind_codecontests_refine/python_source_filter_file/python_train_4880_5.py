def solve(n,left,right):
    if n==10:
        return 1
    if a[n]>left:
        return solve(n+1,a[n],right)
    if a[n]>right:
        return solve(n+1,left,a[n])
    return 0

n=int(input())
for _ in range(n):
    a=[int(i) for i in input().split()]
    print("YES" if solve(10,0,0) else "NO")
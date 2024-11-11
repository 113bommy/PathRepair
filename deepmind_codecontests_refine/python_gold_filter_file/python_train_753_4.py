# cook your dish here
t = int(input())
while t>0:
    n,k = map(int, input().split())
    a = list(map(int, input().split()))
    if k%2!=0:
        m = max(a)
        for i in range(n):
            a[i] = m - a[i]
        print(*a)
    else:
        x = min(a)
        for i in range(n):
            a[i] = a[i] - x
        print(*a)
    t = t-1
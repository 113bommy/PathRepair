for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    if n==1:
        print(0)
        continue
    i = n-1
    while i>=0 and a[i-1] >= a[i]:
        i -= 1
    while i>=0 and a[i-1] <= a[i]:
        i -= 1
    print(i)
    
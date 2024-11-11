n,k = [int(i) for i in input().split()]; ch = 1

if n%2 == 0:
    if k <= n//2:
        k-=1
        print(1+2*k)
    else:
        k -= n//2
        print(2*k)
else:
    if k<=n//2+1:
        k-=1
        print(1+2*k)
    else:
        k -= n//2+1
        print(2*k)
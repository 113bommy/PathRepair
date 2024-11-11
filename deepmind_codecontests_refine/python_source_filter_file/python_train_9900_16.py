n, k = map(int, input().split())
if n+n-1 < k:
    print(0)
elif n-1 > k:
    print((k-1)//2)
else:
    print((2*n-k+1)//2)
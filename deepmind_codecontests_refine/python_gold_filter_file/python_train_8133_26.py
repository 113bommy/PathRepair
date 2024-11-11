n,k=[int(i) for i in input().split()]

if k==1 or k==n:
    print(3*n)
else:
    print((3*n)+min(n-k,k-1))
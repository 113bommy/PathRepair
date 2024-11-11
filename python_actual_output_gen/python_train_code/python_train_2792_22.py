n,k=[int(i) for i in input().split()]
if n==1 or n==k:
    print(3*n)
else:
    print((3*n)+min(n-1,k-1))
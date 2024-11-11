n,k=[int(x) for x in input().split()]
print(' '.join([str(y) for y in list(range(n-k-1))+list(range(n-1,n-k-2,-1))]))
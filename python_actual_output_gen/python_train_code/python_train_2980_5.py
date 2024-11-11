def gpSum(n, a, r):
    return (a*(r**n - 1))/(r-1)

n, l, r = [int(x) for x in input().split()]
ones = (n - l + 1)
mores = (n - r + 1)
minSum = ones
maxSum = mores * 2**(r-1)
if l > 1 :
    minSum += gpSum(n - ones, 2, 2)
if r > 1 :
    maxSum += gpSum(n - mores, 1, 2)
print("%d, %d" % (minSum, maxSum))
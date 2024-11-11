n,k=[int(x) for x in input().split()]
act=n//k*k
while act<=n:
    act+=k
print(act)

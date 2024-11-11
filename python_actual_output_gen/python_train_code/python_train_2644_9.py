n,k=[int(i) for i in input().split()]
if k==0:
    print(1)
elif k>=n//2:
    print(n-k)
else:
    print(k)

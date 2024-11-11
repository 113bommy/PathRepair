w,h = list(map(int,input().split()))
ways = (4)*2*(w-1)
print((ways*(2**(h-1)))%998244353)
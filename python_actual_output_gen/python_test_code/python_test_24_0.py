a,b = [int(i) for i in input().split()]
print((b*b*(b-1)*a*(a+1)/4 + a*(b-1)*b/2)%1000000007)
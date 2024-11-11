a, b = [ int(v) for v in input().split() ]
print(max(a*b,a*(a-1),b*(b-1)))
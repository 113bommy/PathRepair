a, b = [ int(v) for v in input().split() ]
print(max(a+b,a*2+1,b*2+1))
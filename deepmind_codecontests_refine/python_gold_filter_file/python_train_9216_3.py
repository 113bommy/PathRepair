n,a,b,c,d=input().split()
n,a,b,c,d=int(n),int(a),int(b),int(c),int(d)

condl=max(0, d-a, b+d-a-c, b-c)
condh=min(n, n+d-a, n+b+d-a-c, n+b-c)
print(max(0,(condh-condl)*n))
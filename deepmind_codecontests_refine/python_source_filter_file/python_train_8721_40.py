n,m=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]

print("Yes" if len([x for x in a if x>sum(a)/(4*m)])>=m else "No")
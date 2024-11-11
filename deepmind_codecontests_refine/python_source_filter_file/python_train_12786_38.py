a=int(input())
print("Yes" if [4*x+11*y for x in range(26) for y in range(9)].count(a) else "No")
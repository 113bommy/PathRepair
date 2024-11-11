a=int(input())
print("Yes" if [4*x+11*y for x in range(101) for y in range(101)].count(a) else "No")


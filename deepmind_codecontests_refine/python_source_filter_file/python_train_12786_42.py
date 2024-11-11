a=int(input())
print("Yes" if [4*x+11*y for x in range(100) for y in range(15)].count(a) else "No")


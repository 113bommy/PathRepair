X=int(input())
li=[x**p for x in range(2,32) for p in range(2,35) if x**p<=X]
print(max(li))
li=[int(x) for x in input().split()]
k=int(input())
print(max(li)*2**k+sum(li)-max(li))
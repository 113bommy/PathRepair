n,m,k = [int(x) for x in input().split()]

L = [int(x) for x in input().split()]

q = m//(k+1)
r = m%(k+1)

L.sort()

a = L[-1]
b = L[-2]

print(a*k*q+b*q)
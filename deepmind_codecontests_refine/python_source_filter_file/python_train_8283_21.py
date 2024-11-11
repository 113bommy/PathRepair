A = int(input())
B = int(input())
C = int(input())
D = int(input())

a = A ^ B
b = C ^ D
c = B | C
d = A ^ D

e = a | b
f = c ^ d

g = e ^ f

print(g)

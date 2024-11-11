a = int(input())
b = int(input())
c = int(input())
d = int(input())

# a = 1 - a
b = 1 - b
# c = 1 - c
# d = 1 - d

a1 = a | b
b1 = c ^ d
c1 = b & c
d1 = a | d


a2 = a1 & b1
b2 = c1 ^ d1


print(a2 | b2)

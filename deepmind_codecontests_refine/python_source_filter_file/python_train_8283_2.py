a = int(input())
b = int(input())
c = int(input())
d = int(input())

x = a | b
y = c ^ d
z = b & c
t = a | d

k = x & y
m = z ^ t

res = k | m

print(1 - res)

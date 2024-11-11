a = int(input())
b = int(input())
c = int(input())
d = int(input())
w = a & b
x = c | d
y = b ^ c
z = a & d
A = w ^ x
B = y | z
print(A & B)

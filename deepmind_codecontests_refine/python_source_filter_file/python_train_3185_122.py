n = input()
l = int(n[0])
b = int(n[2])
c = 0
while l <= b:
    l = 3 * l
    b = 2 * b
    c += 1
print(c)

a, b = input().split()
a, b = int(a), int(b)

c = [int(x)%2 for x in input().split()]
d = [int(x)%2 for x in input().split()]

e1 = c.count(0)
o1 = c.count(1)
e2 = c.count(0)
o2 = c.count(1)

print(min(e1,o2) + min(e2,o1)) 



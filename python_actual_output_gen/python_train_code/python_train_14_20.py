a,b = input().split(' ')

a,b = int(a),int(b)
c = 0
h = 0

while a >= b:
    h += a
    c += a
    a = int(c/b)
    c = c%b

h += a

print(h)
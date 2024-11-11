temp = [int(x) for x in input().split()]
y = temp[0]
b = temp[1]
r = temp[2]
if y >= b:
    y = b-1
else:
    b = y+1
if b >= r:
    b = r-1
    y = r-2
else:
    r = b+1
print(y, b, r)

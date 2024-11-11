inputs = list(map(int,input().rstrip().rsplit()))

n = inputs[0]
m = inputs[1]
a = inputs[1]

hor = 0
ver = 0

if n% a == 0:
    hor+= n/a
else:
    hor+=int(n/a)+1

if m% a == 0:
    ver+= m/a
else:
    ver+=int(m/a)+1

print(int(hor+ver))
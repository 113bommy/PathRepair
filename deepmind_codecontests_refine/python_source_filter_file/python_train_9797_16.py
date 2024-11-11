import math
n = input().split()
d = int(n[0]) % (2*int(n[1])+1)
t = math.ceil(int(n[0])/(2*int(n[1])+1))
print(t)
if d > int(n[1]):
    p = [k*(2*int(n[1])+1)+int(n[1])+1 for k in range(t)]
    for k in p:
        print(k, end=' ')
else:
    p = [k*(2*int(n[1])+1)+1 for k in range(t)]
    for k in p:
        print(k, end=' ')
n = int(input())
a = list(input())
l = 0
r = 0
u = 0
d = 0
for i in a:
    if i == 'U':
        u+=1
    elif i == 'D':
        d += 1
    elif i == 'L':
        l += 1
    else:
        r += 1
print(min(l,r)+min(u,d))
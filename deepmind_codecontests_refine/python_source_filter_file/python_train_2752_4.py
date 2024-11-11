x = input()
x = [ int(y) for y in input().split()]
z = 0
c = 0
for n in x:
    if n >= 0:
        z+=1
    else:
        if z > 0:
            z-=1
        else:
            c+=1
print(c)
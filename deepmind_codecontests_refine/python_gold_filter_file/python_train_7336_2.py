u = input()
v = input()
z, n = 1001, len(u)
for i in range(n):
    if u[i] != v[i]:
        z = i
        break
if z > 1000:
    print('No such string')
elif ord(v[z]) - ord(u[z]) < 2:
    x, y = 1001, 0
    for i in range(z+1,n):
        if u[i] != 'z':
            x, y = i, 1
            break
        if v[i] != 'a':
            x, y = i, 2
            break
    if y < 1:
        print('No such string')
    else:
        print(u[:z], end = '')
        if y == 1:
            print(u[z:x] + 'z' + u[x+1:n])
        else:
            print(v[z:x] + 'a' + v[x+1:n])
else:
    print(u[:z] + chr(ord(u[z]) + 1) + u[z+1:n])


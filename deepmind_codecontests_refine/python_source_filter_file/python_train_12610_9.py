n = int(input())
s = list(input())
a = [0, 0, 0]
for i in s:
    if i == '0':
        a[0] += 1
    elif i == '1':
        a[1] += 1
    else:
        a[2] += 1
k = n // 3
if a[0] == a[1] and a[1] == a[2]:
    print(''.join(s))
    exit(0)
x = a[0]
y = a[1]
z = a[2]
if x < k:
    for i in range(n):
        if x == k:
            break
        if z > k and s[i] == '2':
            s[i] = '0'
            z -= 1
            x += 1
        elif y > k and s[i] == '1':
            s[i] = '0'
            y -= 1
            x += 1
if z < k:
    for i in range(n - 1, -1, -1):
        if z == k:
            break
        if x > k and s[i] == '0':
            s[i] = '2'
            x -= 1
            z += 1
        if y > k and s[i] == '1':
            s[i] = '2'
            y -= 1
            z += 1
if y < k:
    for i in range(n - 1, -1, -1):
        if y == k:
            break
        if x > k and s[i] == '0':
            s[i] = '1'
            x -= 1
            y += 1
    for i in range(0):
        if y == k:
            break
        if z > k and s[i] == '2':
            s[i] = '1'
            z -= 1
            y += 1
print(''.join(s))
n = input()
c = 0
b = 0

for i in n:
    if i == '4' or i == '7':
        c += 1

c = str(c)

for i in c:
    if i != '4' and i != '7':
        b == 1
        break

if b == 1:
    print("NO")
else:
    print("YES")
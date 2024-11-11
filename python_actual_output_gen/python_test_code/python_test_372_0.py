n = int(input())

names = [0 for i in range(26)]

for i in range(n):
    name = input()
    name = name[:1]
    names[int(ord(name))-97] += 1

x = 0
for i in names:
    if i > 1:
        if i%2 == 0:
            x += i*(i-1)
        else:
            x += ((i+1)*(i-1)/8) + ((i-1)*(i-3)/8)

print(int(x))
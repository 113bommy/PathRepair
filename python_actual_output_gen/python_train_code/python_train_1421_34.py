row = input().split()

a = int(row[0])
b = int(row[1])
c = int(row[2])
d = int(row[3])

misha = max(3*a/10, a - (a/250) * c)
visa  = max(3*b/10, b - (b/250) * d)

if misha == visa : print('Tie')
elif misha > visa : print('Misha')
else: print('Vasye')




from sys import stdin

an = []
aw = []
ab = []

for i in range(0, 8):
    an.append(stdin.readline())
    
 
for i in range(0, 8):
    for j in range(0, 8):
        if an[j][i] == 'W':
            aw.append(j)
            break
        if an[j][i] == 'B':
            break

for i in range(7, -1, -1):
    for j in range(7, -1, -1):
        if an[j][i] == 'B':
            ab.append(8 - j - 1)
            break
        if an[j][i] == 'W':
            break

if not aw:
    print('B')
    exit()

if not ab:
    print('A')
    exit()

maw = min(aw)
mab = min(ab) 

          
print('A' if maw <= mab else 'B')
       

        
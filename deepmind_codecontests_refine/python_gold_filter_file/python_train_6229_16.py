# ARC093D

a,b = map(int, input().split())

if a<=b:
    m = "."
    M = "#"
    mc = a
    Mc = b
else:
    m = "#"
    M = "."
    mc = b
    Mc = a
    
s = [[m]*100 for _ in range(100)]
tmp = [[M,M,M,m],
        [M,m,M,m],
      [M,M,M,m],
      [m,m,m,m]]
tmp2 = [[M,m,m,m],
        [m,m,m,m],
      [m,m,m,m],
      [m,m,m,m]]
i = 0
for i in range(mc-1):
    u,v = (i*4)//100, (i*4)%100
    u *= 4
    for x in range(4):
        for y in range(4):
            s[u+x][v+y] = tmp[x][y]

for j in range(i+1, i+1+(Mc-(mc-1))):
    u,v = (j*4)//100, (j*4)%100
    u *= 4
    for x in range(4):
        for y in range(4):
            s[u+x][v+y] = tmp2[x][y]
print(100,100)
print("\n".join(["".join(item) for item in s]))
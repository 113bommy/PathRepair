# Purification

f = lambda: input()

n = int(f())
m = []

for i in range(n):
    m.append(input())

fr = []
fc = []
fct = [False] *n

for i in range(n):
    for j in range(n):
        if m[i][j] == '.':
            fr.append((i+1, j+1))
            break

for i in range(n):
    if len(fc) < 5:
        for j in range(n):
            if len(fc) > 4:
                break
            
            if m[i][j] == '.':
                if fct[j] == False:
                    fct[j] = True
                    fc.append((i+1, j+1))
            
#print(fr)
#print(fc)
if len(fr) == n:
    for i in range(n):
        print(fr[i][0], fr[i][1])
elif len(fc) == n:
    for i in range(n):
        print(fc[i][0], fc[i][1])
else:
    print(-1)
        
                

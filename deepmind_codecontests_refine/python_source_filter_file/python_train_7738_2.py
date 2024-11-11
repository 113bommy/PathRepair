y = [2]
h = []
j = 0
for i in range(3,1000):
    z = 0
    for x in range(2, int(i**0.5)+1):
        if i%x == 0:
            z+=1
    if z == 0:
        y.append(i)
for i in range(0,len(y)-1):
    x = y[i]+y[i+1]
    h.append(x)

k = list(input().split())
a = int(k[0])
b = int(k[1])

for i in range(0,len(h)):
    h[i] = h[i] + 1

g = []

for i in h:
    z = 0
    for x in range(2, int(i**0.5)+1):
        if i%x == 0:
            z+=1
            
    if z == 0:
        g.append(i)
print(g)

for i in g:
    if i>=2 and i<=a:
        j+=1
if j >= b:
    print("YES")
else:
    print("NO")


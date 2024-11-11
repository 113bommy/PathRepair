n, m = [int(i) for i in input().split(" ")]
b = [0]*n
g = [0]*m
x = [int(i) for i in input().split(" ")][1:]
y = [int(i) for i in input().split(" ")][1:]
#print(x, y)
for i in x:
    b[i] = 1
for i in y:
    g[i] = 1

for i in range(n*m*2):
    h = max(b[i%n], g[i%m])
    b[i%n] = h
    g[i%m] = h
if sum(b)+sum(g) == n+m: print("Yes")
else: print("No")

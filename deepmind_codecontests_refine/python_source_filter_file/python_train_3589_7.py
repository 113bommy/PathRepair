n, m = map(int, input().split())

b = list(map(int, input().split()))
g = list(map(int, input().split()))

b.pop(0)
g.pop(0)

bl = [0 for x in range(n)]
for i in b:
    bl[i] = 1

gl = [0 for x in range(m)]
for i in g:
    gl[i] = 1

for i in range(3*max(n,m)):
    if(bl[i%n] == 1):
        gl[i%m] = 1
    if(gl[i%m] == 1):
        bl[i%n] = 1

if (sum(bl) == len(bl) and sum(gl) == len(gl)):
    print("Yes")
else:
    print("No")

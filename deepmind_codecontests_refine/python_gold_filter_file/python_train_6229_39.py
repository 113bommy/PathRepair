a,b = map(int,input().split())

ans = [["." for i in range(100)] for j in range(100)]

for i in range(100):
    for j in range(50):
        ans[i][j] = "#"

a-=1
b-=1

ind = 0
while True:
    loop = min(a,25)
    for i in range(loop):
        ans[ind][i*2] = "."
    a-=loop
    ind += 2
    if a == 0:
        break

ind = 0
while True:
    loop = min(b,25)
    for i in range(loop):
        ans[ind][51+i*2] = "#"
    b-=loop
    ind += 2
    if b == 0:
        break

print("100 100")
for i in range(100):
    for j in range(99):
        print(ans[i][j],end="")
    print(ans[i][-1])

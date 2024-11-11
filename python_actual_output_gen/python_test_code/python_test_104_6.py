z = int(input())
l = []
res = ""
while z:
    a, b =map(int, input().rstrip().split(" "))
    l.append([a,b])
    z=z-1
o = [l[i][0] for i in range(len(l))]
z = o
o.sort(reverse=True)
if z == [l[i][0] for i in range(len(l))]:
    res = "maybe"
else:
    res = "rated"

for i in l:
    if i[0]!=i[1]:
        res = "rated"
        break

print(res)


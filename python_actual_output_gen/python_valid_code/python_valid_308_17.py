n, m = map(int, input().split())
pos = list()
for j in range(n):
    pos.append(list(map(int, input().split())))
ans = list()
for j in range(n):
    for k in range(pos[j][0], pos[j][0]+1):
        ans.append(k)

new = [x for x in range(1, m+1)]
final = list()
for x in new:
    if x not in ans:
        final.append(x)

if len(final) > 0:
    print(len(final))
    for x in final:
        print(x, end=" ")
else:
    print(0)
    print()

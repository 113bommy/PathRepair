n, k = map(int, input().split())
l = [(int(x),i) for i,x in enumerate(input().split())]
l.sort()

days = 0
ans = []
for i in range(len(l)):
    days += l[i][0]

    if days <= k:
        ans.append(str(l[i][1]))

print(len(ans))
if len(ans) > 0:
    print(' '.join(ans))
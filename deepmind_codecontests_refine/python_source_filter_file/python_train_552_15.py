n,k = map(int,input().split())
l = []
for i in range(n):
    l.append([int(j) for j in input().split()])
imp = []
for i in range(n):
    imp.append(l[i][0]*100 + l[i][1])
imp.sort(reverse = True)
check = imp[k-1]
ans = 0
for i in range(n):
    if imp[i] == check:
        ans += 1
print(ans)
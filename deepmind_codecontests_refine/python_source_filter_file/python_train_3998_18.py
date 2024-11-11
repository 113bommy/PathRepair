n = int(input())
lis = list(map(int,input().split()))
i = -1
j = -1
k = -1
f = 0
for x in range(n-1):
    for y in range(x+1,n):
        p = lis[x] + lis[y]
        if p in lis:
            i = lis.index(p) + 1
            j = y + 1
            k = x + 1
            f = 1
            break
    if f == 1:
        break
if f == 0:
    print(-1)
else:
    print(str(k) + " " + str(j) + " " + str(i))
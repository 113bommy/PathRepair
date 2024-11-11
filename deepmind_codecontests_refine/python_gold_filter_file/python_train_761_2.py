n = int(input())
ans = 0
l = []
d = {}
for i in range(n):
    x,y = map(int,input().split())
    if x in d:
        d[x].append(y)
    else:
        d[x] = [y]
    l.append([x,y])
for i in range(n-1):
    for j in range(i+1,n):
        if (l[i][0]+l[j][0])%2==0 and (l[i][1]+l[j][1])%2==0:
            if (l[i][0]+l[j][0])//2 in d:
                if (l[i][1]+l[j][1])//2 in d[(l[i][0]+l[j][0])//2]:
                    ans += 1
print(ans)
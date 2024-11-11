l = {}
r = {}
for i in range(int(input())):
    x,y=map(int,input().split())
    l[y+x] = l.get(y+x,0) + 1
    r[x-y] = r.get(x-y,0) + 1
ans = 0;
for a in l:
    ans =ans + l[a]*(l[a] -1)//2
for a in r:
    ans =ans + r[a]*(r[a] -1)//2
print(ans)

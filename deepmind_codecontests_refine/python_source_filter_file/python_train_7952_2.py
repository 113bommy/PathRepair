n,m = map(int,input().split())

mp = {}

for i in range(m):
    x,y = map(int,input().strip().split())
    mp[x] = 1
    mp[y] = 1

x = 0
for i in (mp):
    if i+1 not in mp:
        x = i
        break

ans = []
for i in range(n):
    if i!=x:
        ans.append([x+1,i+1])

print(len(ans))
for i in range(len(ans)):
    print(*ans[i])



    

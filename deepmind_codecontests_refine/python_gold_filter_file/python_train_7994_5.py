N = int(input())
l = [[int(j) for j in input().split()] for i in range(N)]
l = sorted(l, key=lambda x:x[1])
s = 0
ans = 'Yes'
for a,b in l:
    s += a
    if s > b:
        ans = 'No'
        break

print(ans)
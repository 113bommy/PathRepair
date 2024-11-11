input()
l = list(map(int,input().split()))
s = set(map(int,input().split()))
ans = []
for e in l:
    if e not in s:
        ans.append(e)
print(*ans)
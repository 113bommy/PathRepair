n,s = map(int,input().split())
l = list(map(int,input().split()))
ans = 0
for i in range(n):
    ans += l[i]
if ans - max(l) < s:
    print("YES")
else:
    print("NO")
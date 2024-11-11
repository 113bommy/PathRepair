n = int(input())
l = [105,165,195]
ans = 0
for i in l:
    if i <= n:
        ans+=1
print(ans)
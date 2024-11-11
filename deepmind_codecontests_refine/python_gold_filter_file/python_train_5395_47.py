n = int(input())
l = [105,165,195,135,189]
ans = 0
for i in l:
    if i <= n:
        ans+=1
print(ans)
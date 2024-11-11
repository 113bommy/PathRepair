n = list(input())
m = list(input())
ans = 0
for i in range(len(n)):
    if n[i] == m[ans]:
        ans += 1
print(ans+1)

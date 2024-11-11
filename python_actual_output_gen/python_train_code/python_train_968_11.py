a, b = map(int, input().split())
ans = 1
for i in range(min(a, b)+1):
    ans = ans * (i+1)
print(ans)
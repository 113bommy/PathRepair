N = int(input())
ans = "second"
for i in range(N):
    a = int(input())
    if a//2 == 1:
        ans = "first"
        break
print(ans)

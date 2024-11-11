n = int(input())
line = list(map(int, input().split()))
ans = -1
for i in range(n):
    ans1 = 0
    for j in range(n):
        if i <= j and line[j] == 0:
            ans1 += 1
        elif i >= j and line[j] == 1:
            ans1 += 1
    ans = max(ans, ans1)
print(ans)
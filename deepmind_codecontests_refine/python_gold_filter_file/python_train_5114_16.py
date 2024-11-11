n = int(input())
l = [0] + list(map(int, input().split())) + [0]
ans = 0
for i in range(n):
    if l[i]== 0 and l[i - 1] == 1 and l[i + 1] == 1:
        ans += 1
        l[i + 1] = 0
print(ans)
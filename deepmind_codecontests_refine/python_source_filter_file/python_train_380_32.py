n = int(input())
p = []
for i in map(int, input().split()):
    p.append(i)
ans1 = 0
ans2 = 0
for i in range(1, n // 2 + 1):
    ans1 += abs(p[i - 1] - ((i - 1) * 2 + 1))
    ans2 += abs(p[i - 1] - i * 2)
print(min(ans1, ans2))
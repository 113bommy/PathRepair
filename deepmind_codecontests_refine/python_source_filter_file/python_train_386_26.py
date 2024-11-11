n = int(input())
a = list(map(int, input().split()))
n = len(a)
ans1 = ans2 = 0
for i in range(n):
    ans1 += abs(a[i] - (i + 1) * 2)
    ans2 += abs(a[i] - (1 + i * 2))
print(min(ans1, ans2))

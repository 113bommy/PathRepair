n = int(input())
l1 = [0, 0] + list(map(int, input().split()))
l2 = [0, 0] + list(map(int, input().split()))
ans1 = [0] * (n + 3)
ans2 = [0] * (n + 3)
for i in range(2, n + 2):
    ans1[i] = max(ans2[i - 1], ans2[i - 2]) + l1[i]
    ans2[i] = max(ans1[i - 1], ans1[i - 2]) + l2[i]
print(max(ans1[n + 1], ans2[n + 1]))
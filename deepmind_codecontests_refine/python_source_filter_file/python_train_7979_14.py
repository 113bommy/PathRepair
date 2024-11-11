c_s = list(map(int, input().strip().split()))
n = list(map(int, input().strip().split()))
ans = [0] * c_s[1]
count = 0
for i in n:
    ans[i - 1] += 1
count = min(ans)
print(count)
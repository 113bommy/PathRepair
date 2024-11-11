M = int(input())
nums = [tuple(map(int, input().split())) for _ in range(M)]
digits = sum(t[1] for t in nums)
d_sum = sum(t[0] * t[1] for t in nums)
ans = digits - 1 + (d_sum - 1) // 9
print(ans)
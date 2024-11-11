n = int(input())

prev1 = 1
prev2 = 1
ans = 1
for i in range(n):
    ab = list(map(int, input().split()))
    if (ab[1] > prev1) and (ab[0] > prev2):
        ans += (min(ab[0], ab[1]) - max(prev1, prev2) + 1)
        if ab[1] < ab[0]:
            prev1 = ab[0]
            prev2 = ab[1]+1
        else:
            prev1 = ab[0]+1
            prev2 = ab[1]
    else:
        prev1 = max(ab[0], prev1)
        prev2 = max(ab[1], prev2)

print(ans)

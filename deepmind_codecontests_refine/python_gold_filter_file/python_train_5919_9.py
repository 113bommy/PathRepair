N = input()
N =int(N)
nums= list(map(int,input().split(" ")))
ans = 1
tend = 0
before = nums[0]
for a in nums[1:]:
    if (before - a) * tend < 0:
        tend = 0
        ans += 1
    else:
        tend = 1 if before - a > 0  else -1 if before - a < 0 else tend

    before = a

print(ans)

import sys
input = sys.stdin.readline


def cum_sum(lst):
    cums = [0] * (len(lst)+1)
    cums[1] = lst[0]
    for i in range(2,len(lst)+1):
        cums[i] = cums[i-1] + lst[i-1]
    return cums
import bisect

t = int(input())
for _ in range(t):
    s = list(input())
    nums = []
    for i in range(len(s)-1):
        if s[i] == "-":
            nums.append(-1)
        else:
            nums.append(1)
    cum_nums = cum_sum(nums)
    nim = min(cum_nums)
    if nim == 0:
        print(len(s)-1)
        continue
    cnt = []
    now_nax = 0
    for i in range(1,len(cum_nums)):
        if cum_nums[i] < now_nax:
            cnt.append(-cum_nums[i])
            now_nax = cum_nums[i]
        else:
            cnt.append(-now_nax)
    ans = 0
    cnt.append(int(1e10))
    cnt.insert(0, -1)
    for i in range(-now_nax+1):
        u = bisect.bisect_right(cnt, i)
        if u == len(cnt)-1:
            u -= 1
        ans += u
    print(ans)
    # ans_u = [1]*(-now_nax+1)
    # print(cnt)
    # for i in range(len(cnt)):
    #     ans_u[cnt[i]] += 1
    # print(ans_u)
    # print(sum(ans_u))



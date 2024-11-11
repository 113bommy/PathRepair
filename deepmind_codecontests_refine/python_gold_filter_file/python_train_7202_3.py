from itertools import product

l, r = map(int, input().split())
lucky_nums = sorted(int(''.join(p)) for r in range(1, 11) for p in product("47", repeat=r))
ans = 0

for lucky_num in lucky_nums:
    if l <= lucky_num <= r:
        ans += (lucky_num - l + 1) * lucky_num
        l = lucky_num + 1
    elif l <= lucky_num and r < lucky_num:
        ans += (r - l + 1) * lucky_num
        break

print(ans)
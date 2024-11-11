k, d, t = (int(x) for x in input().split())

import math as m

if d >= k:
    chunksize = d
    chunkspeed = k + (d-k)/2
else:
    if k % d == 0:
        chunksize = k
    else:
        chunksize = (k // d) * k + 1

    # lcm = k // m.gcd(k, d) * d
    # lft = 0
    # rgt = lcm//d
    # while lft != rgt:
    #     cur = (lft+rgt)//2
    #     if d*cur < k:
    #         lft = cur+1
    #     else:
    #         rgt = cur
    # chunksize = lft * d
    chunkspeed = k + (chunksize-k)/2



chunks = m.floor(t / chunkspeed)
# print(chunksize)
# print(chunkspeed)
ans = chunksize * chunks

rem = t - (chunkspeed * chunks)
if rem <= k:
    ans += rem
else:
    ans += k
    rem -= k
    ans += rem*2

print(ans)
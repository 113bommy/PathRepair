from math import ceil
k, d, t = map(int, input().split())

timeAfterK = ceil(k / d) * d

cookingDone = k / t + (timeAfterK - k) / (2*t)

rounds = int(1 / cookingDone)

cookingLeft = 1 - rounds * cookingDone

# print(timeAfterK, cookingDone, rounds, cookingLeft)

if cookingLeft <= k/t:
    ans = rounds * timeAfterK + cookingLeft * t
else:
    ans = rounds * timeAfterK + k * t
    cookingLeft -= k/t
    ans += cookingLeft * 2 * t

print("{:.10f}".format(ans))
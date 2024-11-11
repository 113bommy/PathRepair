a = [int(x) for x in input().split(" ")]
k = a[0]
d = a[1]
t = a[2]

def solve(remain):
    once = k + remain / 2
    times = t // once
    # final = t - times * once
    final = t % once
    if final <= k:
        timeNeed = final + times * (k + remain)
    else:
        final -= k
        timeNeed = k + final * 2 + times * (k + remain)
    print("{:.1f}".format(timeNeed))
    pass


if k % d == 0:
    print("{:.1f}".format(float(t)))
elif k < d:
    remain = d - k
    solve(remain)
else:
    remain = d - k % d
    solve(remain)

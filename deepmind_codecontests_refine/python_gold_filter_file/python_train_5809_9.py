import itertools
import bisect
n, m = list(map(int, input().split()))
al = list(map(int, input().split()))
al.sort()
ub = al[-1]*3
lb = -1
while lb + 1 < ub:
    target = (ub+lb)//2
    tmp = 0
    for a in al:
        sa = target - a
        # リストAに値xを入れ、xが複数になるとき、一番左の値xのインデックスを返す
        i = bisect.bisect_left(al, sa)
        tmp += (n-i)
    if (tmp >= m):
        lb = target
    else:
        ub = target

target = lb
rui_al = [0] + list(itertools.accumulate(al))
ans = 0
tmp = 0
for a in al:
    sa = target - a
    # リストAに値xを入れ、xが複数になるとき、一番左の値xのインデックスを返す
    i = bisect.bisect_left(al, sa)
    tmp += (n-i)
    ans += (rui_al[-1] - rui_al[i])
    ans += a*(n-i)


if tmp > m:
    ans -= (tmp-m)*target
print(ans)

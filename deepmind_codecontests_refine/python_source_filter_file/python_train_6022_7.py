import bisect
n = int(input())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))
c = sorted(list(map(int, input().split())))
cnt = 0
for bb in b:
    anum = bisect.bisect_left(a, bb)
    cnum = bisect.bisect_right(c, bb)
    cnt += (anum * cnum)
print(cnt)
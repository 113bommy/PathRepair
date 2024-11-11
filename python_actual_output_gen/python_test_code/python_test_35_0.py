import sys
n = int(sys.stdin.readline())

intervals = list(map(lambda x : (int(x[0]), int(x[1])), map(str.split, sys.stdin.readlines())))
intervals = list(enumerate(intervals))

intervals.sort(key=lambda x : 1000000009 * x[1][0] - x[1][1])

r = 0
ans1 = -1
ans2 = -1
for interval in intervals:
    if interval[1][1] < r:
        ans1 = interval[0]
        break
    else:
        ans2 = interval[0]
        r = max(r, interval[1][1])

if ans1 == -1:
    print('-1 -1')
else:
    print(ans1 +1, ans2 +1)

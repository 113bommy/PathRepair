import sys
t1, t2, t = map(int, input().split())
u = 1
n = int(input())
if n == 0:
    print(t1)
    sys.exit()
a = [int(i) for i in input().split()]
mini = 10 ** 10
ans = 0
time = t1
for x in a:
    if x <= t2 - t:
        if time - x + 1 < mini and x > 0:
            mini = time - x + 1
            if x - 1 > time:
                ans = time
            else:
                ans = x - 1
        time = t + max(time, x)
if time > t2 - t:
    print(ans)
else:
    print(time)

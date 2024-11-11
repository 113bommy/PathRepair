import sys

n, a = map(int, sys.stdin.readline().split())
tn = list(map(int, sys.stdin.readline().split()))

ans = 0
if tn[a-1] is 1:
    ans = 1

dis = 1
while True:
    if a - dis < 1 and a + dis > n:
        break
    elif a - dis < 1:
        if tn[a+dis-1] is 1:
            ans += 1
    elif a + dis > n:
        if tn[a-dis-1] is 1:
            ans += 1
    else:
        if tn[a-dis-1] is 1 and tn[a+dis-1] is 1:
            ans += 2

    dis += 1

print(ans)

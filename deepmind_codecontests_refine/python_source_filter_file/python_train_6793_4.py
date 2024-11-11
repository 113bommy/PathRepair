import sys
lines = sys.stdin.readlines()
# (N, K) = map(int, lines[0].strip().split(" "))
(n, p) = map(int, lines[0].strip().split(" "))
arr = list(map(int, lines[1].strip().split(" ")))
arr.sort()
counter = {}
for a in arr:
    if a not in counter:counter[a] = 0
    counter[a] += 1

lower = max(arr[-1] - n + 1, 1)
l, r = lower-1, arr[-1] + 1

def check(val):
    pt = 0
    cnt = 0
    while pt < n and arr[pt] <= val:
        cnt += 1; pt += 1
    if cnt >= p: return False
    while cnt >= 0:
        val += 1
        cnt -= 1
        if val in counter: cnt += counter[val]
        if cnt >= p: return False
        if val >= arr[-1]: break
    return not( cnt < 0 or val < arr[-1])

cnt = 0
res = []
for i in range(lower, arr[-1]+1):
    if check(i):
        cnt += 1
        res.append(i)

print(cnt)
print(' '.join(map(str, res)))
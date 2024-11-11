import sys

N, K = map(int, sys.stdin.readline().split(" "))
a = list(map(int, sys.stdin.readline().split(" ")))

ans = float("inf")
for i in range(2**N):
    pattern = []
    for j in range(N):
        pattern.append(i >> j & 1)
    if sum(pattern) < K:
        continue
    # print(pattern)

    max_h = 0
    tmp_ans = 0
    for n in range(N):
        if pattern[n] == 1:
            if a[n] <= max_h:
                tmp_ans += max_h - a[n] + 1
                max_h += 1
        max_h = max(max_h, a[n])
    ans = min(ans, tmp_ans)
    
print(ans)
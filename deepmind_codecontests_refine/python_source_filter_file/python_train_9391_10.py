res = []
for t in range(int(input())):
    a, b, c, r = list(map(int, input().split(" ")))
    left_cov = c - r
    right_cov = c + r
    min_dist = min(a,b)
    max_dist = max(a,b)
    m = max(left_cov, min_dist)
    n = min(right_cov, max_dist)
    diff_dist = n - m
    res.append(abs(a-b) - diff_dist)
for x in res:
    print(x)
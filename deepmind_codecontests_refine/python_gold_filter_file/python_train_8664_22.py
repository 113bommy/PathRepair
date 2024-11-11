n, m = map(int, input().split())
l = list(map(int, input().split()))
s = sum(l)

def solve():
    if s < n:
        return [-1]
    for i in range(m):
        if l[i] > n - i:
            return [-1]

    ov = s - n
    idx = 1
    sln = []

    for i in range(m):
        if ov > 0 and idx != 1:
            d = min(ov, l[i-1]-1)
            idx -= d
            ov -= d
        sln.append(idx)
        idx += l[i]

    return sln

print(*solve())

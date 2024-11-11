red, blue = [int(x) for x in input().split()]

def red_first():
    n, m, score = red - 1, blue, 0
    diff = min(n // 2, m // 2) * 2
    n -= diff
    m -= diff
    score += diff

    if m == 0:
        score += n
    elif m == 1:
        score += max(n - 1, 0)
    elif n == 0:
        score += m - 1
    else:
        score += 1 + max(m - 3, 0)
    return score

def blue_first():
    n, m, score = red, blue - 1, 0
    diff = min(n // 2, m // 2) * 2
    n -= diff
    m -= diff
    score += diff

    if n == 0:
        score += m
    elif n == 1:
        score += max(m - 1, 0)
    elif m == 0:
        score += n - 1
    else:
        score += 1 + max(n - 3, 0)
    return score

res = max(red_first(), blue_first())
print(res, red + blue - 1 - res)

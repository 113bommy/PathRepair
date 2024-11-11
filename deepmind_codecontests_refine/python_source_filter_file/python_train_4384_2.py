w, h, k = map(int, input().split())

def c(w, h, k):
    if k == 0 or w < 2 or h < 2:
        return 0
    else:
        return 2 * w + 2 * (h - 2) + c(w - 2, h - 2, k - 1)


print(c(w, h, k))

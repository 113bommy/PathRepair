def f(W, H):
    res = float('INF')
    w = W // 2
    for h in range(1, H):
        res = min(res, max(h * W, (H - h) * w,  (H - h) * (W - w)
                           ) - min(h * W, (H - h) * w,  (H - h) * (W - w)))
    return min(H, res)


def main():
    H, W = map(int, input().split())
    if H % 3 == 0 or W % 3 == 0:
        print(0)
    else:
        print(min(f(W, H), f(H, W)))


main()

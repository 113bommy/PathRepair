def main():
    H, n = map(int, input().split())
    d = list(map(int, input().split()))

    s = [0]

    for x in d:
        s.append(s[-1] + x)

    mn = min(s)
    dif = s[-1]

    t = 0
    if H <= mn:
        for x in s:
            if H + x <= 0:
                print(t)
                return
            t += 1
    else:
        if dif >= 0:
            print(-1)
            return
        else:
            ts = (H + mn - dif - 1) // -dif
            t += n * ts
            H += dif * ts
            for x in s:
                if H + x <= 0:
                    print(t)
                    return
                t += 1

main()
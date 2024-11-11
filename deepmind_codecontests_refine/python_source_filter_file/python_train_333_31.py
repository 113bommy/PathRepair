def main():
    n, m = map(int, input().split())
    aa, bb = [m] * 200001, [0] * 200001
    for i in sorted(map(int, input().split())):
        aa[i] -= 1
        t = 1
        while i:
            i //= 2
            if not aa[i]:
                break
            aa[i] -= 1
            bb[i] += t
            t += 1
    print(min(b for a, b in zip(aa, bb) if not a))


if __name__ == '__main__':
    main()

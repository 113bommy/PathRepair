def comb(m, n):
    if m == 0 or n == m:
        return 1
    num = 1
    for i in range(1, n + 1):
        num *= i
    den = 1
    for i in range(1, m + 1):
        den *= i
    for i in range(1, n - m + 1):
        den *= i
    return int(num / den)


def main():
    line = input()
    l = line.split(' ')
    for i in range(0, len(l)):
        l[i] = int(l[i])
    n = l[0]
    m = l[1]
    t = l[2]
    ans = 0
    for b in range(4, n + 1):
        g = t - b
        if g < 1 or g > m:
            continue
        ans += comb(b, n) * comb(g, m)        
    print(int(ans))

if __name__ == "__main__":
    main()
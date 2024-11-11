def main():
    import sys
    def input(): return sys.stdin.readline().rstrip()
    n = int(input())
    a = list(map(int, input().split()))

    x = 0
    for i in range(2, n):
        x ^= a[i]
    d = a[0]+a[1]-x
    if d%2 == 1 or d < 0:
        print(-1)
        return
    d >>= 1
    if d&x != 0 or d > a[0]:
        print(-1)
        return
    k = x.bit_length()
    tmp = d
    # d^tmp はd&x=0からd|tmpと一緒
    for i in range(k, -1, -1):
        if (x >> i) & 1:
            if tmp+1<<i <= a[0]:
                tmp += 1<<i
    if 0 < tmp <= a[0]:
        print(a[0]-tmp)
    else:
        print(-1)



if __name__ == '__main__':
    main()
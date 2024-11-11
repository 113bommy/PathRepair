def main():
    N = int(input())
    if N == 3:
        ans = [2, 3, 6]
    else:
        ans = []
        lst = [2, 3, 4, 6, 8, 9, 10, 12]
        for i in range(N//8):
            ans += list(map(lambda x: x + i*12, lst))
        b = N//8
        m = N % 8
        for i in range(4):
            if m >= 2:
                ans += [b*12+lst[i], b*12+lst[6-i]]
                m -= 2
            elif m == 1:
                ans += [b*12+6]
                break
    print(*ans)

if __name__ == "__main__":
    main()

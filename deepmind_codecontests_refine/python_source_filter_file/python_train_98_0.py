def main():
    while True:
        n = int(input())
        if n == 0:
            exit()
        f = [s for input().split()]
        pm = 'd'
        cnt = 0
        for m in f:
            if m[1] == pm:
                cnt += 1
            pm = m[1]
        print(cnt)

if __name__ == '__main__':
    main()
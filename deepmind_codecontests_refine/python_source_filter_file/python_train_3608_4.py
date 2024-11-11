def main():
    n = int(input())
    a = [int(c) for c in input().split()]

    s = sum(a)
    i = 0
    cur = 0
    while cur < s // 2:
        cur += a[i]
        i += 1

    print(i)

if __name__ == '__main__':
    main()

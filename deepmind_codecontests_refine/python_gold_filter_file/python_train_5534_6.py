def main():
    n, k = map(int, input().split())
    if n < k*(k+1)//2:
        print('NO')
    else:
        add = (n-k*(k+1)//2) // k
        res = [x+add for x in range(1, k+1)]
        left = n-sum(res)
        added = True
        while left > 0 and added:
            added = False
            pos = k-1
            while pos > 0:
                while left > 0 and res[pos]+1 <= 2*res[pos-1]:
                    res[pos] += 1
                    left -= 1
                    added = True
                pos -= 1

        ok = True
        for i in range(k-1):
            if res[i+1]<=res[i] or res[i+1] > 2*res[i]:
                ok = False
                break
        if ok and left == 0:
            print('YES')
            print(*res)
        else:
            print('NO')


if __name__ == '__main__':
    main()

def main():
    n, k = map(int, input().split())
    a = [int(c) for c in input().split()]

    mx = 1000 * n
    idx = -1
    
    for i in range(k):
        res = 0
        j = i
        
        for j in range(i, i + n, k):
            res += a[j % n]

        if res < mx:
            mx = res
            idx = i + 1

    print(idx)

if __name__ == '__main__':
    main()

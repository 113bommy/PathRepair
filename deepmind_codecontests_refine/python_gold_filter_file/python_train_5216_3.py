if __name__ == '__main__':
    n = int(input().strip())
    arr = [int(__) for __ in input().strip().split()]
    if n == 1:
        print(1)
    else:
        cur, ma = 1, 1
        for i in range(1, n):
            if arr[i] <= 2 * arr[i - 1]:
                cur += 1
                ma = max(cur, ma)
            else:
                cur = 1
        print(ma)
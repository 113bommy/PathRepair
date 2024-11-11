def solve():
    n = int(input())
    encoded = input()

    res = [''] * n
    j = 1
    if n % 2 == 1:
        idx = n // 2
        res[idx] = encoded[0]
        for i in range(1, n//2 + 1):
            res[idx-i] = encoded[j]
            res[idx+i] = encoded[j+1]
            j += 2
    else:
        idx = n//2 - 1
        res[idx] = encoded[0]
        for i in range(1, n//2):
            res[idx-i] = encoded[j]
            res[idx+i] = encoded[j+1]
            j += 2

        res[-1] = encoded[-1]

    print(''.join(res))


if __name__ == "__main__":
    solve()
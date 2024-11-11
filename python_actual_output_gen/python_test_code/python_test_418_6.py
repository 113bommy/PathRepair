def solve():
    n = int(input())
    encoded = input()

    res = [''] * n
    is_even = n % 2 == 0
    mid = n // 2 - 1 if is_even else n // 2
    res[mid] = encoded[0]
    q = -1 if is_even else 1
    for i in range(1, mid+1):
        res[mid-i*q] = encoded[2*i-1]
        res[mid+i*q] = encoded[2*i]

    #res[-1] = encoded[-1]
    print(''.join(res))


if __name__ == "__main__":
    solve()
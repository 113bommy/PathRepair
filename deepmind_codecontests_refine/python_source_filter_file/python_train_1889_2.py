def main():
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    kek = 0
    for i in range(n):
        if kek * 2 >= arr[i]:
            ans += arr[i] >> 1
            kek -= arr[i] >> 1
            kek += arr[i] & 1
        else:
            ans += kek
            arr[i] -= kek
            ans += arr[i] // 3
            arr[i] %= 3
            kek = arr[i]
    print(ans)
    return 0
main()
def main():
    n, p, k = map(int, input().split())
    ans = list(map(int, input().split()))
    for i in range(n):
        temp = ans[i]
        ans[i] = (temp ** 4 - temp) % p
    mp = {}
    for i in ans:
        mp.setdefault(i, 0)
        mp[i] = mp[i] + 1
    temp = 0
    for i in mp.values():
        temp = (i * (i - 1)) // 2 + temp
    print(temp)


if __name__ == "__main__":
    main()
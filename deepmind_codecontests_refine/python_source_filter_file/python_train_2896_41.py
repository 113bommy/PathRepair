def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(n-1):
        a[i+1] += a[i]
    b = []
    for i in range(-1, n-1):
        for j in range(i+1, n):
            if i == -1:
                b.append(a[j])
            else:
                b.append(a[j]-a[i])
    ans = 0
    for i in reversed(range(31)):
        cnt = 0
        for v in b:
            if ans & v == ans and (1<<i) & v != 0:
                cnt += 1
        if k <= cnt:
            ans += (1<<i)
    print(ans)

if __name__ == "__main__":
    main()

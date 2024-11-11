def main():
    n = int(input())
    X = list(map(int, input().split()))

    ans = [-1]*(n**2)
    left = []
    right = []
    for idx, x in enumerate(X):
        idx += 1
        ans[x-1] = idx
        left.append((x, idx-1, idx))
        right.append((x, n-idx, idx))

    left.sort(key=lambda x: -x[0])
    right.sort(key=lambda x: x[0])

    amt, cnt = 0, 0

    for i in range(n**2):
        if ans[i] != -1:
            continue
        while amt == 0 and cnt < n:
            cnt += 1
            x, amt, idx = left.pop()
        if amt == 0:
            break
        if x <= i:
            print("No")
            return
        amt -= 1
        ans[i] = idx

    amt, cnt = 0, 0

    for i in range(n**2-1, -1, -1):
        if ans[i] != -1:
            continue
        while amt == 0 and cnt < n:
            cnt += 1
            x, amt, idx = right.pop()
        if amt == 0:
            break
        if x >= i:
            print("No")
            return
        amt -= 1
        ans[i] = idx
    print("Yes")
    print(*ans)


main()

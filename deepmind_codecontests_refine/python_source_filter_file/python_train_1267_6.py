

def solve(arr, x, y, n):
    res = 0

    for i in range(x, n):
        before = arr[i-x:i]
        after = arr[i+1:i+y+1]

        done1 = True
        for a in before:
            if arr[i] > a:
                done1 = False
                break

        if not done1:
            continue

        done2 = True
        for b in after:
            if arr[i] > b:
                done2 = False
                break

        if done1 and done2:
            res = i + 1
            break

    if res == 0:
        print(n)
    else:
        print(res)


def main():
    n, x, y = map(int, input().split())
    arr = list(map(int, input().split()))

    solve(arr, x, y, n)


if __name__ == "__main__":
    main()
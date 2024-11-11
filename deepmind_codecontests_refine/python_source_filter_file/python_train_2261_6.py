if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    cnt = 0

    for i in range(0, 2 * n - 1, 2):
        if arr[i] != arr[i + 1]:
            idx = None
            for j in range(i + 2, 2 * n - 1):
                if arr[j] == arr[i]:
                    idx = j
                    break
            for j in reversed(range(i + 1, idx)):
                tmp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = tmp
                cnt += 1

    print(cnt)
if __name__ == '__main__':
    arr = []
    for i in range(1, 2000):
        if i % 3 == 0 or i % 10 == 3:
            continue
        arr.append(i)

    t = int(input())
    for _ in range(t):
        k = int(input())
        print(arr[k - 1])

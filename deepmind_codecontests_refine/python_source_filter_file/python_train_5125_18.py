
def main():
    for _ in range(int(input())):
        n, d = map(int, input().split(" "))
        arr = list(map(int, input().split(" ")))
        i = 0
        r = 0
        while d > 0 and i < n - 1:
            i = i + 1
            while arr[i] != 0:
                arr[i] -= i
                d -= i
                if d >= 0:
                    r += 1
                else:
                    break

        print(arr[0] + r)


if __name__ == '__main__':
    main()

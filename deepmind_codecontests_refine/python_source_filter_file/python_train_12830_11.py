def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    arr = sorted(arr, key=lambda x: x)
    for i in range(n - 1, 0, -1):
        if arr[i] <= i + 1:
            return i + 2
    return 1


def main():
    t = int(input())
    for i in range(t):
        print(solve())


main()

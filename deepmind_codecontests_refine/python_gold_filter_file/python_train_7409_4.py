from math import ceil


def solve(arr, n, d):
    count = 0
    for i in range(1, n):
        if arr[i - 1] > arr[i]:
            v = ceil((arr[i - 1] - arr[i]) / d)
            count += v
            arr[i] += v * d
        if arr[i - 1] == arr[i]:
            count += 1
            arr[i] += d
    return count


def main():
    vars = list(map(int, input().split(" ")))
    arr = list(map(int, input().split(" ")))
    # for i in range(n):
    #     arr.append(list(map(int, list(input()))))
    print(solve(arr, *vars))


main()

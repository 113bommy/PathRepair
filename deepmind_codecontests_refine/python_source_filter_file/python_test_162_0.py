
def read_ints():
    return [int(x) for x in input().rstrip().rsplit()]


def ok(arr, k):
    test_arr = arr.copy()
    for i in range(len(arr)-1, 1, -1):
        if test_arr[i] < k:
            return False
        d_i = min(test_arr[i] - k, arr[i])
        test_arr[i - 1] += d_i // 3
        test_arr[i - 2] += (d_i // 3) * 2

    return test_arr[0] >= k and test_arr[1] >= k

def binarySearch(arr) -> int:
    bad = 1000000
    good = 0
    while abs(bad - good) > 1:
        middle = (bad + good) // 2
        if ok(arr, middle):
            good = middle
        else:
            bad = middle

    return good


if __name__ == '__main__':
    nn = int(input())

    while nn > 0:
        n = int(input())
        arr = read_ints()
        print(binarySearch(arr))

        nn -= 1


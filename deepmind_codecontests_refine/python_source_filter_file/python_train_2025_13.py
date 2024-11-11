from sys import stdin, stdout


def shift(alist):
    return [alist[len(alist)-1]] + alist[:len(alist)-1]


def solve(ints, n):
    i = 0
    while i < n - 1:
        if ints[i] > ints[i+1]:
            sliced = ints[i+1:]
            if sliced == sorted(sliced) and sliced[len(sliced)-1]<ints[0]:
                return len(sliced)
            return -1
        i += 1
    return 0


if __name__ == "__main__":
    n = int(stdin.readline().rstrip())
    integers = list(map(int, stdin.readline().rstrip().split()))
    stdout.write(str(solve(integers, n)))


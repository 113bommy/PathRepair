cache = {}

def makekey(b, arr):
    return (b, ) + tuple(arr)

def solve(b, arr):
    if b == 0 or not arr:
        return 0

    key = makekey(b, arr)
    if key not in cache:
        result = 0
        n_odd = 0
        n_even = 0
        for i in range(len(arr) - 1):
            if arr[i] % 2 == 0:
                n_even += 1
            else:
                n_odd += 1

            if n_even == n_odd:
                cost = abs(arr[i] - arr[i + 1])
                if cost <= b:
                    result = max(result, 1 + solve(b - cost, arr[i + 1:]))

        cache[key] = result
    return cache[key]


def main():
    n, b = map(int, input().split())
    arr = list(map(int, input().split()))
    print(solve(b, arr))

main()

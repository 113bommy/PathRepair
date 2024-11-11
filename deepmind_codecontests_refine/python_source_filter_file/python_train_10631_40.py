MOD = 10000

def solve():
    _ = input()
    arr =  [int(x) for x in input().split()]

    print(len(arr) + 1)
    total_adds = 0
    for i in reversed(range(len(arr))):
        add_x = (i - (arr[i] + total_adds)) % MOD
        print(1, i+1, add_x)
        total_adds += add_x

    print(1, len(arr), MOD)

solve()


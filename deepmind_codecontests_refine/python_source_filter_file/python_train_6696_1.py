# https://codeforces.com/contest/1534/problem/B
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here
t = int(input())


def isPeak(x, arr):
    return arr[x-1] < arr[x] > arr[x+1]


def calc(arr):
    ans = 0
    for x in range(1, len(arr)-1):
        if arr[x] > arr[x-1]:
            ans += arr[x] - arr[x-1]
        if arr[x] > arr[x+1]:
            ans += arr[x] - arr[x+1]
    return ans


for _ in range(t):
    n = int(input())
    arr = [0] + list(map(int, input().split())) + [0]
    moves = 0
    # temp = [0 for x in range(n+2)]
    for x in range(1, n):
        if isPeak(x, arr):
            mx = max(arr[x-1], arr[x+1])
            moves += (arr[x] - mx)
            # arr[x] = mx
            arr[x] = mx
    # [rint]
    # print(temp)
    print(calc(arr) + moves)

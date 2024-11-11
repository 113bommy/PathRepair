# https://codeforces.com/contest/1189/problem/C


def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    arr_sum = [0]
    for index, num in enumerate(arr):
        arr_sum.append(arr_sum[index] + arr[index])
    q = int(input())
    for _ in range(q):
        range_index = [int(x) for x in input().split()]
        print(int((arr_sum[range_index[1]] - arr_sum[range_index[0]]) / 10))


if __name__ == '__main__':
    solve()

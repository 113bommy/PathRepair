from typing import List


def first_calculation(array: List[int]):
    dp: List[int] = [1] * len(array)
    par: List[int] = [i for i in range(0, len(array))]

    for i in range(1, len(array)):
        if array[i] > array[i - 1]:
            dp[i] = dp[i - 1] + 1
            par[i] = par[i - 1]
        else:
            for j in range(par[i - 1], i):
                par[j] = i - 1

    for i in range(par[-1], len(array)):
        par[i] = len(array) - 1

    return dp, par


def with_removing(array: List[int], dp: List[int], par: List[int]):
    max_ret = 0
    for i in range(1, len(array)-1):

        if par[i] != par[i-1] and array[i+1] > array[i-1]:
            if array[i] > array[i+1]:
                max_ret = max(max_ret, dp[i-1] + dp[par[i+1]])
            else:
                max_ret = max(max_ret, dp[i-1] + dp[par[i+1]]-1)
    return max_ret


def solution(array: List[int]):
    dp, par = first_calculation(array)
    removed_element = with_removing(array, dp, par)
    return max(max(dp), removed_element)

_ = int(input())
array = list(map(int, input().split()))
print(solution(array))

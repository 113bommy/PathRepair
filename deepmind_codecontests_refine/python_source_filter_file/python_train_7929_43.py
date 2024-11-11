import os


def f(a_arr, b_arr):
    return f"{max(a_arr)} {b_arr[0]}"


if os.environ.get('DEBUG', False):
    print(f"{f([20], [10, 20])} = 20 20")
    print(f"{f([3, 2, 2], [1, 5, 7, 7, 9])} = 3 1")
    print(f"{f([1, 3, 5, 7], [7, 5, 3, 1])} = 1 1")
else:
    n = int(input())
    a_arr = list(map(int, input().split()))
    m = int(input())
    b_arr = list(map(int, input().split()))
    print(f(a_arr, b_arr))

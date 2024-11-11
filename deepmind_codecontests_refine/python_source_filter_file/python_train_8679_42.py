# python 3
"""
"""


def next_test(n_int, indices_int) -> int:
    occupied = [0 for i in range(3000 + 1)]
    for each in indices_int:
        occupied[each] = 1
    for i in range(1, n_int + 1):
        if occupied[i] == 0:
            return i


if __name__ == "__main__":
    """
    Inside of this is the test. 
    Outside is the API
    """
    n = int(input())
    indices = list(map(int, input().split()))

    print(next_test(n, indices))

def main_function():
    n, l, r = [int(i) for i in input().split(" ")]
    min_a_sum = (n - l) + 2 ** l - 1
    max_a_sum = (2 ** r) - 1 + (n - r) * 2 ** (r - 1)
    return f"{min_a_sum} {max_a_sum}"


print(main_function())











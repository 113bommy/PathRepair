n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

memo = {}


def f(a, b, i, is_last_el_a, memo):
    if (i, is_last_el_a) in memo:
        return memo[(i, is_last_el_a)]

    if i == 0:
        if is_last_el_a:
            memo[(i, is_last_el_a)] = a[0]
        else:
            memo[(i, is_last_el_a)] = b[0]
        return memo[(i, is_last_el_a)]

    if i == 1:
        if is_last_el_a:
            memo[(i, is_last_el_a)] = a[1] + b[0]
        else:
            memo[(i, is_last_el_a)] = b[1] + a[0]
        return memo[(i, is_last_el_a)]

    cur_value = b[i]
    if is_last_el_a:
        cur_value = a[i]
    memo[(i, is_last_el_a)] = max(f(a, b, i - 1, not is_last_el_a, memo) + cur_value,
                                  f(a, b, i - 2, not is_last_el_a, memo) + cur_value)
    return memo[(i, is_last_el_a)]


max_height = -1
for i in range(1, n):
    max_height = max(f(a, b, n-1, True, memo), f(a, b, n-1, False, memo))
print(max_height)

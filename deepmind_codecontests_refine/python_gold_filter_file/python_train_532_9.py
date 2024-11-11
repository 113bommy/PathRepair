

def f(n, m, k, p_arr, s_arr, c_arr):
    i_p_s_c_arr = []
    for i in range(n):
        i_p_s_c_arr.append((i + 1, p_arr[i], s_arr[i], (i + 1) in c_arr))

    i_p_s_c_arr.sort(key=lambda x: (x[2], -x[1]))
    count = 0
    for i in range(1, n):
        if i_p_s_c_arr[i][3] and i_p_s_c_arr[i][2] == i_p_s_c_arr[i - 1][2]:
            count += 1
    return count


# print(f"{f(7, 3, 1, [1, 5, 3, 4, 6, 7, 2], [1, 3, 1, 2, 1, 2, 3], [3])} = 1")
# print(f"{f(8, 4, 4, [1, 2, 3, 4, 5, 6, 7, 8], [4, 3, 2, 1, 4, 3, 2, 1], [3, 4, 5, 6])} = 2")

n, m, k = list(map(lambda _: int(_), input().split(' ')))
p_arr = list(map(lambda _: int(_), input().split(' ')))
s_arr = list(map(lambda _: int(_), input().split(' ')))
c_arr = list(map(lambda _: int(_), input().split(' ')))
print(f(n, m, k, p_arr, s_arr, c_arr))
# 
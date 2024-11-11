def fill_arr(river, remaing_sum, cursor, size_ci, ind):
    # bool_left = True
    # if cursor + size_ci > remaing_sum: # fill left side
    #     river[cursor - size_ci + 1: cursor + 1] = [ind] * size_ci

    # else: # fill right side

    # bool_left = False
    return river


n, m, d = [*map(int, input().split())]
Ci = [*map(int, input().split())]
river = [0] * (n + 1)
cursor = 0
total_platform_size = sum(Ci)
used_platform = 0
bool_capasity = False
for i, c in enumerate(Ci):
    ind = i + 1
    if bool_capasity:
        d = c

    cursor += d
    used_platform += c
    remaining_platforms_size = total_platform_size - used_platform
    capasity = n - (cursor + c -1)
    if capasity  <= remaining_platforms_size:
        bool_capasity = True
        cursor = cursor + capasity - remaining_platforms_size
    river[cursor:cursor + c] = [ind] * c
    if c > 1:
        cursor = cursor + c -1
river.pop(0)

if cursor + d >= n:
    print("Yes")
    print(* river)
else:
    print("NO")

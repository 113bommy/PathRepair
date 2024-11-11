def solver():
    first_num, second_num = map(int, input().split())

    if first_num == second_num:
        print("YES")
        return 0

    base_2_first_num_rev = ""
    base_2_second_num_rev = ""

    def div_mod2(a):
        return a // 2, a % 2

    while first_num > 0:
        first_num, coef = div_mod2(first_num)
        base_2_first_num_rev += str(coef)

    while second_num > 0:
        second_num, coef = div_mod2(second_num)
        base_2_second_num_rev += str(coef)

    base_2_first_num, base_2_second_num = base_2_first_num_rev[::-1], base_2_second_num_rev[::-1]

    if base_2_second_num[-1] == "0":
        print("NO")
        return 0

    n = len(base_2_first_num)
    n_1 = len(base_2_second_num) - n
    for i in range(n_1):
        check = base_2_second_num[i:i + n]
        not_until_now = base_2_second_num[i + n:]
        until_now = base_2_second_num[:i]
        if check == base_2_first_num_rev or check == base_2_first_num:
            if not (("0" in until_now) or ("0" in not_until_now)):
                print("YES")
                return 0

    while base_2_first_num[-1] == "0":
        base_2_first_num = base_2_first_num[:-1]
        base_2_first_num_rev = base_2_first_num_rev[1:]
    n = len(base_2_first_num)
    n_1 = len(base_2_second_num) - n

    for i in range(n_1):
        check = base_2_second_num[i:i + n]
        not_until_now = base_2_second_num[i + n:]
        until_now = base_2_second_num[:i]
        if check == base_2_first_num_rev or check == base_2_first_num:
            if not (("0" in until_now) or ("0" in not_until_now)):
                print("YES")
                return 0

    print("NO")
    return 0


solver()

for q in range(int(input())):
    str_1 = input()
    str_2 = input()
    len_1 = len(str_1)
    len_2 = len(str_2)
    ans = False
    for i in range(len_1):
        for j in range(0, len_1 - i):
            k = len_2 - 1 - j
            if i + j < k:
                continue
            l1 = i
            r = i + j
            l2 = r - k
            if str_1[l1:r+1] + str_1[l2:r][::-1] == str_2:
                ans = True
    print('yes' if ans else 'no')

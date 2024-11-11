querries = int(input())
for _ in range(querries):
    raw_in = input().split()
    [n,k] = [int(x) for x in raw_in]
    string = input()
    str_len = len(string)
    full = "RGB"*668
    all_pos = [full[:str_len], full[1:str_len+1], full[2:str_len+2]]
    max_val = k
    if k < n:
        for i in range(3):
            check_dif = []
            for j in range(str_len):
                if string[j] != all_pos[i][j]:
                    check_dif.append(1)
                else:
                    check_dif.append(0)
            count = 0
            for u in range(k,n):
                check_min = sum(check_dif[count:u])
                if check_min < max_val:
                    max_val = check_min
                count += 1
    else:
        for i in range(3):
            check_min = 0
            for j in range(str_len):
                if string[j] != all_pos[i][j]:
                    check_min += 1
            if check_min < max_val:
                max_val = check_min
    print(max_val)


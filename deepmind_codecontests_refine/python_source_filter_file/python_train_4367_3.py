while 1:
    s1 = input().split('\"')
    if s1[0] == '.': break
    s2 = input().split('\"')

    jdg = 1
    cnt_d = 

    if len(s1) != len(s2): print("DIFFERENT")
    else:
        l = len(s1)
        i = 0
        while i < l:
            if s1[i] != s2[i]:
                cnt_d += 1
                if cnt_d == 1 and i % 2 == 1:
                    jdg = 1
                else:
                    jdg = 0
                    break
            i += 1

        if jdg == 1 and cnt_d == 1: print("CLOSE")
        elif jdg == 0 or cnt_d > 1: print("DIFFERENT")
        else: print("IDENTICAL")


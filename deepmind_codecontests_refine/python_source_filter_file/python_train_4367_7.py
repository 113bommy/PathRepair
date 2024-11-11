while(1):
    a = input()
    if(a == '.'):
        break
    b = input()
    n = len(a)
    m = len(b)
    l = 0;
    flag = 0
    idx_dif = 0
    error_cou = 0

    while(1):
        if(l >= n-1 or l+idx_dif >= m-1):
            flag = 2

        if(flag == 0):
            for i in range(l,n):
                if(a[i] == '\"'):
                    if(i+idx_dif < m and a[l:i] == b[l+idx_dif:i+idx_dif]):
                        l = i+1
                        flag = 1
                    else:
                        flag = 2
                    break

                elif(i == n-1):
                    if(a[l:i] != b[l+idx_dif:m-1]):
                        flag = 2
                    else:
                        l = n-1
                    break
                if(flag != 0):
                    break

        elif(flag == 1):
            for i in range(l,n):
                if(a[i] == '\"'):
                    for j in range(l+idx_dif,m):
                        if(b[j] == '\"'):
                            if(a[l:i] != b[l+idx_dif:j]):
                                error_cou += 1
                            idx_dif = j-i
                            l = i+1
                            flag = 0
                            break
                        if(j == m-1):
                            flag = 2
                            break

                if(flag != 1):
                    break

        if(flag == 2 or l >= n-1 or l+idx_dif >= m-1):
            break

    if(error_cou >= 2 or flag == 2):
        print("DIFFERENT")
    elif(error_cou == 1):
        print("CLOSE")
    elif(error_cou == 0):
        print("IDENTICAL")

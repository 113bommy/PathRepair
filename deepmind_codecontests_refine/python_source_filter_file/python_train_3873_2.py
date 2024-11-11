t = int(input())
for l in range(t):
    n = int(input())
    s = list(input())
    k = list(input())
    i = 0
    swap = 0
    ans = list()
    flag2 = False
    while (i < n) and (swap <= 2*n) and (not flag2):
        if s[i] == k[i]:
            i += 1
        else:
            flag = True
            for j in range(i+1, n):
                if s[j] == s[i]:
                    omg = k[i]
                    k[i] = s[j]
                    s[j] = omg
                    ans.append([i+1, j+1])
                    i += 1
                    swap += 1
                    flag = False
                    break
            if flag:
                for j in range(i+1, n):
                    if s[i] == k[j]:
                        omg = k[j]
                        k[j] = s[-1]
                        s[-1] = omg
                        ans.append([n, j+1])
                        omg = k[i]
                        k[i] = s[-1]
                        s[-1] = omg
                        ans.append([n, i+1])
                        swap += 2
                        i += 1
                        flag = False
            if flag:
                flag2 = True

    if flag2:
        print('NO')
    else:
        if swap >= 2*n:
            print('NO')
        else:
            print('YES')
            print(swap)
            for zaw in ans:
                print(zaw[0],zaw[1])
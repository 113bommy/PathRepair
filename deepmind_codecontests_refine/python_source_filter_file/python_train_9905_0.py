def problem_1138b():
    n = int(input())
    c = input()
    a = input()
    n0, c0, a0, b0 = 0, 0, 0, 0
    for i in range(n):
        if c[i] == '0' and a[i] == '0':
            n0 += 1
        elif c[i] == '0' and a[i] == '1':
            a0 += 1
        elif c[i] == '1' and a[i] == '0':
            c0 += 1
        else:
            b0 += 1
    half_n = int(n/2)
    for i in range(half_n):
        if b0 > 2*i:
            continue
        if a0 < i and c0 < i:
            if i - a0 + i - c0 == b0:
                em = half_n - i
                d1 = i - c0
                cc = i
                if em > n0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and em:
                        em -= 1
                        print(str(i+1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1':
                        continue
                    elif c[i] == '1' and a[i] == '0' and cc:
                        cc -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d1:
                        d1 -= 1
                        print(str(i + 1) + ' ', end='')
                return
        elif c0 < i <= a0:
            d1 = b0 - i + c0
            d2 = a0 - i
            if i >= d1 >= 0:
                d5 = i - c0
                d3 = d2 + d1
                d4 = half_n - i - d3
                cc = i
                if d4 > n0 or d4 < 0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and d4:
                        d4 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1' and d3:
                        d3 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '0' and cc:
                        cc -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d5:
                        d5 -= 1
                        print(str(i + 1) + ' ', end='')
                return
        elif a0 < i <= c0:
            d1 = b0 - i + a0
            if 0 <= d1 <= i:
                cc = i - d1
                d2 = half_n - cc - d1
                if d2 > n0 or d2 < 0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and d2:
                        d2 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1':
                        continue
                    elif c[i] == '1' and a[i] == '0' and cc:
                        cc -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d1:
                        d1 -= 1
                        print(str(i + 1) + ' ', end='')
                return
        else:
            d1 = int(b0 / 2)
            d2 = i - d1
            d3 = b0 - d1
            d4 = i - d3
            d5 = c0 - d2
            d6 = a0 - d4
            if d6 + d1 + d2 <= half_n and d3 + d4 + d5 <= half_n:
                d7 = half_n - d6 - d1 - d2
                if d7 > n0 or d2 < 0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and d7:
                        d7 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1' and d6:
                        d6 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '0' and d2:
                        d2 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d1:
                        d1 -= 1
                        print(str(i + 1) + ' ', end='')
                return
    print(-1)
    return


if __name__ == '__main__':
    problem_1138b()

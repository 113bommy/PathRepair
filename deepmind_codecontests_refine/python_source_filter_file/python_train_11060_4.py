for _ in range(int(input())):
    n = int(input())
    if n % 4 == 0:
        print('NO')
        continue
    else:
        print('YES')
        m = n // 2
        even = list(range(2, m * 2 + 2, 2))
        odd = list(range(1, m * 2 - 1, 2))
        odd.append(sum(even) - sum(odd))
        lst = even + odd
        print(*lst)



for _ in range(int(input())):
    n = int(input())
    s = input()
    if '0' in s:
        ind = s.find('0')
        if ind+1 <= n // 2:
            print(ind + 1, n, ind + 2, n)
        else:
            print(1, ind + 1, 1, ind)
    else:
        print(1, (n//2)*2, 1, n//2)
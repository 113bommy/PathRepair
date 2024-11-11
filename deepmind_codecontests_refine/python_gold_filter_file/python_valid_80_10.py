for _ in range(int(input())):
    n = int(input())
    s = input()
    m = n//2
    if '0' not in s:
        print(1, m, 2, m+1)
    else:
        i = s.index('0')
        if i >= m:
            print(1, i+1, 1, i)
        else:
            print(i+1, i+1+m, i+2, i+1+m)

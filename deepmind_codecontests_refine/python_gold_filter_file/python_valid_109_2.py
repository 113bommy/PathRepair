for _ in range(int(input())):
    n = int(input())
    s = str(input())
    res = sum([int(i) for i in s]) + len(s) - s.count('0')
    print( res-1 if s[n-1] != '0' else res)


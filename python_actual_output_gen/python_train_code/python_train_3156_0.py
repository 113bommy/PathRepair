for _ in range(int(input())):
    n = int(input())
    print('YNEOS'[n&(n-1)::2])

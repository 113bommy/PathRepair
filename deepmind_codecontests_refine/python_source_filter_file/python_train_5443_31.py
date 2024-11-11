for _ in range(int(input())):
    l,r=map(int,input().split())
    print('YNEOS'[0 if l>=r/2 else 1::2])
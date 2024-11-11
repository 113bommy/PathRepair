for _ in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    if sum(s)%2:
        print('YES')
    else:
        total = sum(i for i in s if i%2)
        if 0 < total < len(s):
            print('YES')
        else: print('NO')
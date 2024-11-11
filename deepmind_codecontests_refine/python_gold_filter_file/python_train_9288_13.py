for _ in range(int(input())):
    (n,d) =list(int(x) for x in input().split())
    x = int(d**0.5-1)
    if n>=x+int((d/(x+1))+0.999999999999):
        print('YES')
    else:
        print('NO')
while(1):
    n = input()
    if n == '-':
        exit()
    m = int(input())
    for i in range(m):
        h = int(input())
        n = n[h:] + n[0:h]
    print(n)
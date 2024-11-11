while True:
    n = int(input())
    if n == 0:
        break
    org = ''
    dist = ''
    for i in range(n):
        c1, c2 = input().split()
        org += c1
        dist += c2
    m = int(input())
    oSt = ''
    for i in range(m):
        oSt += input()
    print(oSt.translate(str.maketrans(org, dist)))
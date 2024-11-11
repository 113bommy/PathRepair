for i in range(int(input())):
    n, m = map(int, input().split())
    s1 = list(map(int, input().split()))
    s2 = list(map(int, input().split()))
    ch = True
    for i in range(n):
        for j in range(m):
            if s1[i] == s2[j]:
                print('YES')
                print(1, s2[j])
                ch = False
    if ch:
        print('NO')
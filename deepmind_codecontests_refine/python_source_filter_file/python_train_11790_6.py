for _ in range(int(input())):
    n = int(input())
    ls = []
    for i in range(n):
        ls.append(list(map(int, input().split()))[1:])
    pr = [True] * n
    mr = [False] * n
    c = 0
    for i in range(n):
        k = ls[i]
        for j in k:
            if pr[j - 1]:
                pr[j - 1] = False
                mr[i] = True
                c += 1
                break
    if c == n:
        print("OPTIMAL")
    else:
        a = 0
        b = 0
        for i in range(n):
            if not mr[i]:
                a = i + 1
                break
        for i in range(n):
            if pr[i]:
                b = i + 1
                break
        print("IMPROVISE")
        print(a, b)

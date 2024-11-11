def fog():
    s = list(map(int, input().split()))
    n = s[0]
    k = s[1]
    lst = []
    sm = 0
    for i in range(n-1):
        lst.append(1)
    if k == 1:
        print(1)
    elif n == 1:
        print(2)
    elif k == 2:
        print(n+1)
    elif n == 2:
        print(k+1)

    else:
        for i in range(k-2):
            lst1 = [sum(lst)]
            for i in range(n-2):
                lst1.append((lst1[i] - (lst[-i-1])) % (10**9+7))
            sm += sum(lst1) % (10**9+7)
            sm = (sm % (10**9+7))
            lst = lst1
        print(sm+1+n)

t = int(input())
while t > 0:
    t -= 1
    fog()

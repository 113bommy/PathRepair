for _ in range(int(input())):
    a,b,q = map(int,input().split())
    p = [0]*(a*b)
    for j in range(1,a*b):
        p[j] = p[j-1]+1
        if (((j % a) % b) != ((j % b) % a)):
            p[j] = p[j] + 1

    m = []
    for i in range(q):
        l,r = map(int,input().split())
        x = r//len(p)
        y = (l-1)//len(p)
        m.append(p[r % (len(p))] - p[(l - 1) % (len(p))] + (x - y) * p[-1])

    print(*m)
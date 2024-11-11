k = int(input())
for i in range(k):
    n = int(input())
    c = input()
    a = c.count('a')
    b = c.count('b')
    if a != b:
        maxi = 0
        for i in range(n):
            if maxi != 0:
                break
            for j in range(i+1, n+1):
                a = c[i:j].count('a')
                b = c[i:j].count('b')
                if a == b:
                    maxi = len(c[i:j])
                    print(i+1, j)
                    break
        if maxi == 0:
            print(-1,-1)
    else:
        print(1, len(c))
    